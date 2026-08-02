/*
██╗   ██╗██╗   ██╗██╗   ██╗██████╗  █████╗      ██╗
╚██╗ ██╔╝██║   ██║██║   ██║██╔══██╗██╔══██╗     ██║
 ╚████╔╝ ██║   ██║██║   ██║██████╔╝███████║     ██║
  ╚██╔╝  ██║   ██║╚██╗ ██╔╝██╔══██╗██╔══██║██   ██║
   ██║   ╚██████╔╝ ╚████╔╝ ██║  ██║██║  ██║╚█████╔╝
   ╚═╝    ╚═════╝   ╚═══╝  ╚═╝  ╚═╝╚═╝  ╚═╝ ╚════╝
*/

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
    if(x_parent==y_parent){
        return ;
    }
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
    vector<int>arr(n+1);
    int mn=1e18;
    int idx=-1;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(mn>arr[i]){
            idx=i;
            mn=arr[i];
        }
    }
    parent.resize(n+1);
    Rank.resize(n+1,0);
    for(int i=0;i<=n;i++)parent[i]=i;
    int ans=0;
    vector<tuple<int,int,int>>vec;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        vec.push_back({w,x,y});
    }
    for(int i=1;i<=n;i++){
        if(idx!=i)vec.push_back({arr[idx]+arr[i],idx,i});
    }
    sort(vec.begin(),vec.end());
    for(auto [w,u,v] :vec){
        if (find(u)!=find(v)){
            Union(u,v);
            ans+=w;
        }
    }
    cout<<ans<<endl;
    return 0;
}