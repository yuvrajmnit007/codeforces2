#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
vector<int>ans,path,pos;
bool found=0;
void dfs(vector<int>&vis,int i,unordered_map<int,vector<int>>&adj,int parent){
    vis[i]=1;
    pos[i]=path.size();
    path.push_back(i);
    for(auto it:adj[i]){
        if(it==parent)continue;
        if(!vis[it]){
            dfs(vis,it,adj,i);
            if(found)return;
        }else if(pos[it]!=-1){
            int sz=path.size()-pos[it];
            if(sz>=k+1){
                for(int r=pos[it];r<path.size();r++){
                    int p=path[r];
                    ans.push_back(p);
                }
                found=true;
                return ;
            }
        }
    }
    pos[i]=-1;
    path.pop_back();
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n+1,0);
    pos.resize(n+1,-1);
    for(int i=1;i<=n&&!found;i++){
        if(vis[i]==0){
            dfs(vis,i,adj,0);
        }
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}