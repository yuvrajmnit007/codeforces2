#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,vector<int>>adj;
stack<int>st;
void dfs(int node,vector<int>&vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis);
        }
    }
    st.push(node);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        adj.clear();
        while(!st.empty())st.pop();
        vector<pair<int,int>>vec;
        for(int i=0;i<m;i++){
            int u,v,p;
            cin>>p>>u>>v;
            if(p==1){
                adj[u].push_back(v);
            }
            vec.push_back({u,v});
        }
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,vis);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        vector<int>pos(n+1);
        for(int i=0;i<n;i++){
            pos[ans[i]]=i;
        }
        bool cycle=0;
        //ham ye dekh rhe he ki kahi agar koi esa to nhi he adj of i me jo uske topological order me uske child se pahle to nhi aa rha basiclly cycle dekh rhe he 
        for(int i=1;i<=n;i++){
            for(auto j:adj[i]){
                if(pos[i]>pos[j]){
                    cycle=true;
                }
            }
        }
        if(cycle){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            for(auto it:vec){
                if(pos[it.first]<pos[it.second]){
                    cout<<it.first<<" "<<it.second<<endl;
                }else{
                    cout<<it.second<<" "<<it.first<<endl;
                }
            }
        }
    }
    return 0;
}