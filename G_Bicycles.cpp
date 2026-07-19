#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=1;i<=m;i++) {
            int u,v,wt;
            cin>>u>>v>>wt;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        } 
        vector<int>vec(n+1);
        for(int i=1;i<=n;i++){
            cin>>vec[i];
        }
        vector<vector<int>>dist(n+1,vector<int>(1001,1e18));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        dist[1][vec[1]]=0;
        pq.push({0,1,vec[1]});
        while(!pq.empty()){
            auto [d,u,mn]=pq.top();
            pq.pop();
            if(d!=dist[u][mn]) continue;
            for(auto [v,w]:adj[u]){
                int newmn=min(mn,vec[v]);
                int nd=d+1LL*w*mn;
                if(nd<dist[v][newmn]){
                    dist[v][newmn]=nd;
                    pq.push({nd,v,newmn});
                }
            }
        }
        int ans=1e18;
        for(int mn=1;mn<=1000;mn++){
            ans=min(ans,dist[n][mn]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
