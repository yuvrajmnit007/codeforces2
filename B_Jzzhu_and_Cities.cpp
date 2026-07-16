#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    unordered_map<int,vector<pair<int,int>>>adj;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    vector<int>result(n+1,1e18);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    result[1]=0;
    while(!pq.empty()){
        auto t=pq.top();
        pq.pop();
        int dist=t.first;
        int node=t.second;
        if(dist>result[node])continue;
        for(auto it:adj[node]){
            int v=it.first;
            int wt=it.second;
            if(dist+wt<result[v]){
                result[v]=dist+wt;
                pq.push({result[v],v});
            }
        }
    }
    int ans=0;
    for(int i=0;i<k;i++){
        int v,wt;
        cin>>v>>wt;
        if(result[v]>=wt)ans++;
    }
    cout<<ans<<endl;
    return 0;
}