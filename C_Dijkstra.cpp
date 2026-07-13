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
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    vector<int>result(n+1,1e18);
    vector<int>parent(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    result[1]=0;
    parent[1]=1;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int dist=it.first;
        for(auto p:adj[node]){
            int v=p.first;
            int wt=p.second;
            if(wt+dist<result[v]){
                result[v]=wt+dist;
                parent[v]=node;
                pq.push({wt+dist,v});
            }
        }
    }
    vector<int>ans;
    int node=n;
    while(node!=1){
        ans.push_back(node);
        if(node==parent[node]){
            cout<<-1<<endl;
            return 0;
        }
        node=parent[node];
    }
    ans.push_back(1);
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}