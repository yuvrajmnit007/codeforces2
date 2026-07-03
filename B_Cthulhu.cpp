#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,vector<int>>adj;
vector<int>vis;
void dfs(int node){
    vis[node]=1;
    for(auto &it:adj[node]){
       if(!vis[it])dfs(it);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(m!=n){
        cout<<"NO"<<endl;
        return 0;
    }
    vis.resize(n+1,0);
    vis[1]=1;
    dfs(1);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"FHTAGN!"<<endl;
    return 0;
}