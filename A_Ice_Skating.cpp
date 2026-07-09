#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>parent;
vector<int>Rank;
int ans;
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
        parent[x_parent]=y_parent;
        Rank[x_parent]++;
        ans--;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ans=n;
    parent.resize(n);
    Rank.resize(n,0);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        vec.push_back({u,v});
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(vec[i].first==vec[j].first||vec[i].second==vec[j].second){
                Union(i,j);
            }
        }
    }
    cout<<ans-1<<endl;
    return 0;
}