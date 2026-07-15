#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<pair<int,int>>>adj;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,2*wt});
        adj[v].push_back({u,2*wt});
    }
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans(n+1,1e18);
    for(int i=1;i<=n;i++){
        adj[0].push_back({i,arr[i-1]});
        adj[i].push_back({0,arr[i-1]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto t=pq.top();
        pq.pop();
        int dist=t.first;
        int node=t.second;
        for(auto it:adj[node]){
            int v=it.first;
            int wt=it.second;
            if(dist+wt<ans[v]){
                ans[v]=dist+wt;
                pq.push({ans[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}