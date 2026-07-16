#include <bits/stdc++.h>
using namespace std;
#define int long long
//in the older solution we ignored the multiple path via train from 1->v 
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
    vector<int>trains(n+1,1e18);
    int ans=0;
    for(int i=0;i<k;i++){
        int v,wt;
        cin>>v>>wt;
        if(trains[v]!=1e18)ans++;
        trains[v]=min(trains[v],wt);
    }
    vector<int>result(n+1,1e18);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    result[1]=0;
    vector<int>train_used(n+1,0);
    for(int i=2;i<=n;i++){
        if(trains[i]!=1e18){
            train_used[i]=1;
            result[i]=trains[i];
            pq.push({trains[i],i});
        }
    }
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
                train_used[v]=0;
                pq.push({result[v],v});
            }else if(dist+wt==result[v]&&train_used[v]){
                train_used[v]=0;
                pq.push({result[v],v});
            }
        }
    }
    for(int i=2;i<=n;i++){
        ans+=(train_used[i]==0&&trains[i]!=1e18);
    }
    cout<<ans<<endl;
    return 0;
}