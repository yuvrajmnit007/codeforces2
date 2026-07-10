#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,vector<int>>adj;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>degree(n+1,0);
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        vec.push_back({u,v});
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    queue<int>q;
    for(int i=1;i<n+1;i++){
        if(degree[i]==1){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            degree[it]--;
            if(degree[it]==1){
                q.push(it);
            }
        }
    }
    queue<pair<int,int>>q1;
    vector<int>distance(n+1,1e18);
    for(int i=1;i<=n;i++){
        if(degree[i]==2){
            q1.push({i,0});
            distance[i]=0;
        }
    }
    while(!q1.empty()){
        pair<int,int>p=q1.front();
        q1.pop();
        int node=p.first;
        int dist=p.second;
        distance[node]=dist;
        for(auto it:adj[node]){
            if(distance[it]>dist+1){
                distance[it]=dist+1;
                q1.push({it,dist+1});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<distance[i]<<" ";
    }
    cout<<endl;
    return 0;
}