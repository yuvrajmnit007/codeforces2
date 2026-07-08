#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,vector<int>>adj;
bool bfs(int i,vector<int>&color){
    queue<int>q;
    q.push(i);
    color[i]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto j:adj[node]){
            if(color[j]==0){
                color[j]=-color[node];
                q.push(j);
            }else{
                if(color[j]==color[node]&&j!=node){
                    return false;
                }
            }
        }
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>vec;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        vec.push_back({u,v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>color(n+1,0);
    bool ans=1;
    for(int i=1;i<=n;i++){
        if(color[i]==0&&!adj[i].empty()){
            if(!bfs(i,color)){
                ans=0;
                break;
            }
        }
    }
    if(!ans){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        string ans="";
        for(int i=0;i<m;i++){
            int u=vec[i].first;
            if(color[u]==-1){
                ans+='0';
            }else if(color[u]==1){
                ans+='1';
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}