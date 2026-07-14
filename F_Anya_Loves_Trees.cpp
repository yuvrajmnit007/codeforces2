#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,vector<int>>adj;
bool possible;
vector<int>min_val,arr;
vector<int>max_val;
vector<int>sz;
void dfs(int node){
    if(adj[node].empty()){
        min_val[node]=arr[node];
        max_val[node]=arr[node];
        sz[node]=1;
        return;
    }
    vector<int>c_mins;
    for(auto it:adj[node]){
        dfs(it);
        min_val[node]=min(min_val[node],min_val[it]);
        max_val[node]=max(max_val[node],max_val[it]);
        sz[node]+=sz[it];
        c_mins.push_back(min_val[it]);
    }
    if(max_val[node]-min_val[node]+1!=sz[node]){
        possible=false;
    }
    int drops=0;
    int m=c_mins.size();
    for(int i=0;i<m;i++){
        if(c_mins[i]>c_mins[(i+1)%m]){
            drops++;
        }
    }
    if(drops>1){
        possible=false;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        for(int i=2;i<=n;i++){
            int p;
            cin>>p;
            adj[p].push_back(i);
        }
        arr.resize(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        min_val.resize(n+1,1e18);
        max_val.resize(n+1,-1e18);
        sz.resize(n+1,0);
        dfs(1);
        if(possible){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}