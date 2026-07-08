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
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>color(n+1,0);
    bool ans=true;
    for(int i=0;i<=n;i++){
        if(color[i]==0&&!adj[i].empty()){
            if(!bfs(i,color)) {
                ans=false;
                break;
            }
        }
    }
    if(ans){
        vector<int>a,b;
        for(int i=0;i<=n;i++){
            if(color[i]==-1){
                a.push_back(i);
            }else if(color[i]==1){
                b.push_back(i);
            }
        }
        cout<<a.size()<<endl;
        for(auto it:a){
            cout<<it<<" ";
        }
        cout<<endl;
        cout<<b.size()<<endl;
        for(auto it:b){
            cout<<it<<" ";
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}