#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,vector<int>>adj1;
unordered_map<int,vector<int>>adj2;
int bfs(int s,int t,int o){
    queue<pair<int,int>>q;
    unordered_map<int,bool>vis;
    q.push({s,0});
    vis[s]=1;
    int cnt=0;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int node=it.first;
        int dist=it.second;
        if(node==t&&cnt<=1)return dist;
        if(o==1){
            for(auto it:adj1[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,dist+1});
                }
            }
            if(adj1[node].size()==0) cnt++;
            if(cnt>1)return 1e18;
            else if(cnt==1){
                q.push({node,dist});
            }
            o=2;
        }else{
            for(auto it:adj2[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,dist+1});
                }
            }
            if(adj2[node].size()==0) cnt++;
            if(cnt>1)return 1e18;
            else if(cnt==1){
                q.push({node,dist});
            }
            o=1;
        }
    }
    return 1e18;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++){
        int u,v,o;
        cin>>u>>v>>o;
        if(o==1){
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }else{
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
    }
    int ans=min(bfs(s,t,1),bfs(s,t,2));
    if(ans==1e18){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}