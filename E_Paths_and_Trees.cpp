#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<pair<int,int>>>adj;
    map<pair<int,int>,pair<int,int>>mp;
    for(int i=1;i<=m;i++) {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
        mp[{u,v}]={i,wt};
        mp[{v,u}]={i,wt};
    }
    int src;
    cin>>src;
    vector<int>result(n+1,1e18);
    vector<int>parent(n+1,-1);
    vector<int>parentedge(n+1,-1);
    vector<int>parentwt(n+1,1e18);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    result[src] = 0;
    pq.push({0,{src,-1}});
    while(!pq.empty()){
        auto [dist, cur]=pq.top();
        pq.pop();
        auto [node,par]=cur;
        if(dist!=result[node]) continue;
        for(auto [to,wt]:adj[node]){
            if(result[to]>dist+wt){
                result[to]=dist+wt;
                parent[to]=node;
                parentedge[to]=mp[{node,to}].first;
                parentwt[to]=wt;
                pq.push({result[to],{to,node}});
            }
            else if(result[to]==dist+wt&&wt<parentwt[to]){
                parent[to]=node;
                parentedge[to]=mp[{node,to}].first;
                parentwt[to]=wt;
            }
        }
    }
    int total=0;
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(parentedge[i]!=-1){
            total+=parentwt[i];
            ans.push_back(parentedge[i]);
        }
    }
    cout<<total<<endl;
    for(int it:ans)cout<<it<<" ";
    cout<<endl;
    return 0;
}