#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=998244353;
int cnt1=0,cnt0=0;
bool dfs(int node ,vector<int>&color,unordered_map<int,vector<int>>&adj,int currcolor){
    color[node]=currcolor;
    if(currcolor)cnt1++;
    if(!currcolor)cnt0++;
    for(auto it:adj[node]){
        if(color[it]==color[node])return false;
        if(color[it]==-1){
            color[it]=1-currcolor;
            if(!dfs(it,color,adj,color[it]))return false;
        }
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>power(3e5+1);
    int temp;
    power[0]=1;
    for(int i=1;i<=3e5;i++){
        power[i]=power[i-1]*2;
        power[i]%=MOD;
    }
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        unordered_map<int,vector<int>>adj;
        vector<int>color(n+1,-1);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                cnt1=0,cnt0=0;
                if(!dfs(i,color,adj,1)){
                    ans=0;
                    break;
                }
                ans=ans*((power[cnt0]+power[cnt1])%MOD)%MOD;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}