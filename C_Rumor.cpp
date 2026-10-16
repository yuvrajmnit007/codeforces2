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
    if(Rank[x_parent]<Rank[y_parent]){
        parent[x_parent]=y_parent;
    }else if(Rank[x_parent]>Rank[y_parent]){
        parent[y_parent]=x_parent;
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
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    parent.resize(n+1,0);
    Rank.resize(n+1,0);
    iota(parent.begin(),parent.end(),0);
    while(m--){
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        mp[find(i+1)].push_back(i+1);
    }
    int ans=0;
    for(auto it:mp){
        int mx=1e18;
        for(auto x:it.second){
            mx=min(mx,vec[x-1]);
        }
        ans+=mx;
    }
    cout<<ans<<endl;
    return 0;
}