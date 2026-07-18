#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<pair<int,int>>>adj;
    for(int i=1;i<=m;i++) {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    map<int,vector<int>>mp;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int x;
            cin>>x;
            mp[i].push_back(x);
        }
    }
    vector<int>result(n+1,1e18);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    result[1]=0;
    while(binary_search(mp[1].begin(),mp[1].end(),result[1]))result[1]++;
    pq.push({result[1],1});
    while(!pq.empty()){
        auto [dist,node]=pq.top();
        pq.pop();
        if(dist!=result[node]) continue;
        int cur=dist;
        while(binary_search(mp[node].begin(),mp[node].end(),cur))cur++;
        for(auto [to,wt]:adj[node]){
            if(result[to]>cur+wt){
                result[to]=cur+wt;
                pq.push({cur+wt,to});
            }
        }
    }   
    if(result[n]==1e18)cout<<-1<<endl;
    else cout<<result[n]<<endl;
    return 0;
}