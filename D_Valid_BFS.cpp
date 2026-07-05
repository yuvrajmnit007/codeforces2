#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>arr(n);
    vector<int>order(n+1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        order[arr[i]]=i;
    }
    if(arr[0]!=1){
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++) {
        sort(adj[i].begin(),adj[i].end(),[&](int a,int b){
            return order[a]<order[b];
        });
    }
    vector<int>ans,vis(n+1,0);
    queue<int>q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        vis[node]=1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                q.push(it);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]!=ans[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}