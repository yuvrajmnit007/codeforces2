#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>parent,Rank;
int find(int node){
    if(node==parent[node])return node;
    return parent[node]=find(parent[node]);
}
void Union(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent==y_parent)return;
    if(Rank[x_parent]>Rank[y_parent]){
        parent[y_parent]=x_parent;
    }else if(Rank[y_parent]>Rank[x_parent]){
        parent[x_parent]=y_parent;
    }else{
        parent[x_parent]=y_parent;
        Rank[y_parent]++;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    Rank.resize(n+1,0);
    parent.resize(n+1,0);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    int ans=0;
    unordered_map<int,int>mp;
    for(int i=0;i<=n;i++){
        mp[find(i)]++;
    }
    for(auto it:mp){
        if(it.second>1){
            ans+=it.second-1;
        }
    }
    int temp=pow(2,ans);
    cout<<temp<<endl;
    return 0;
}