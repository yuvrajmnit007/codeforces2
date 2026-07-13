#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>parent,Rank;
vector<pair<int,int>>cycle;
int find(int node){
    if(node==parent[node])return node;
    return parent[node]=find(parent[node]);
}
void Union(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent==y_parent){
        cycle.push_back({x,y});
        return;
    }
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
    int n;
    cin>>n;
    Rank.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    // cout<<"set size "<<st.size()<<endl;
    vector<int>comp;
    for (int i=1;i<=n;i++){
        if(find(i)==i)
            comp.push_back(i);
    }
    cout<<cycle.size()<<endl;
    for(int i=0;i<cycle.size();i++) {
        cout<<cycle[i].first<<" "<<cycle[i].second<<" "<<comp[i]<<" "<<comp[i+1]<<endl;
    }
    return 0;
}