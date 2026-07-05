#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,vector<int>>adj;
vector<int>path;
bool found=0;
vector<pair<int,int>>ans;
vector<int>is_adj_u;
void dfs(vector<int>&vis,int curr,int parent,int u){
    if(found)return;
    vis[curr]=1;
    path.push_back(curr);
    for(auto nxt:adj[curr]){
        if(found)return;
        if(nxt==u&&path.size()>=2){
            int chord_idx=0;
            for(int i=(int)path.size()-2;i>=0;i--){
                if(is_adj_u[path[i]]){
                    chord_idx=i;
                    break;
                }
            }
            vector<int>cycle;
            unordered_set<int>in_cycle;
            cycle.push_back(u);
            in_cycle.insert(u);
            for(int i=chord_idx;i<path.size();i++){
                cycle.push_back(path[i]);
                in_cycle.insert(path[i]);
            }
            for(size_t i=0;i<cycle.size();i++){
                ans.push_back({cycle[i],cycle[(i+1)%cycle.size()]});
            }
            int extra_cnt=0;
            for(int neighbor:adj[u]){
                if(!in_cycle.count(neighbor)){
                    ans.push_back({u,neighbor});
                    extra_cnt++;
                    if(extra_cnt==2)break;
                }
            }
            if(extra_cnt==2){
                found=true;
                return;
            }else{
                ans.clear();
            }
        }else if(!vis[nxt]&&nxt!=u){
            dfs(vis,nxt,curr,u);
        }
    }
    path.pop_back();
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        adj.clear();
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        found=false;
        ans.clear();
        is_adj_u.assign(n+1,0);
        for(int i=1;i<=n;i++){
            if(adj[i].size()<4)continue;
            for(int neighbor:adj[i])is_adj_u[neighbor]=1;
            vector<int>vis(n+1,0);
            vis[i]=1;
            path.clear();
            for(int neighbor:adj[i]){
                if(!vis[neighbor]){
                    dfs(vis,neighbor,i,i);
                    if(found)break;
                }
            }
            for(int neighbor:adj[i])is_adj_u[neighbor]=0;
            if(found)break;
        }
        if(!found){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            cout<<ans.size()<<endl;
            for(auto edge:ans)cout<<edge.first<<" "<<edge.second<<endl;
        }
    }
    return 0;
}