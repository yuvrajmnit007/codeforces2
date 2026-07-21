#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>parent,Rank;
int find(int node){
    if(parent[node]==node)return node;
    return parent[node]=find(parent[node]);
}
void Union(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent==y_parent)return;
    if(Rank[x_parent]>Rank[y_parent]){
        parent[y_parent]=x_parent;
    }else if(Rank[x_parent]<Rank[y_parent]){
        parent[x_parent]=y_parent;
    }else{
        parent[y_parent]=x_parent;
        Rank[x_parent]++;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    parent.resize(n+1,0);
    Rank.resize(n+1,0);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    set<int>st;
    vector<pair<int,int>>vec;
    vector<int>degree(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        degree[u]++;
        degree[v]++;
        vec.push_back({u,v});
        if(find(u)==find(v)){
            st.insert(find(u));
        }
        else Union(u,v);
    }
    int ans=0;
    unordered_map<int,vector<int>>mp;
    for(int i=1;i<=n;i++){
        if(st.find(find(i))!=st.end()){
            mp[find(i)].push_back(i);
        }
    }
    for(auto it:mp){
        bool ok=true;
        for(int i:it.second){
            if(degree[i]!=2){
                ok=false;
                break;
            }
        }
        ans+=ok;
    }
    cout<<ans<<endl;
    return 0;
}