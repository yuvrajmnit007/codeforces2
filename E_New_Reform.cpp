#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>parent,Rank;
vector<bool>cycle;
int find(int node){
    if(parent[node]==node)return node;
    return parent[node]=find(parent[node]);
}
void Union(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent==y_parent){
        cycle[x_parent]=1;
        return;
    }
    if(Rank[x_parent]>Rank[y_parent]){
        parent[y_parent]=x_parent;
        if(cycle[y_parent])cycle[x_parent]=1;
    }else if(Rank[x_parent]<Rank[y_parent]){
        parent[x_parent]=y_parent;
        if(cycle[x_parent])cycle[y_parent]=1;
    }else{
        parent[x_parent]=y_parent;
        if(cycle[x_parent])cycle[y_parent]=1;
        Rank[y_parent]++;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    cycle.resize(n+1,0);
    Rank.resize(n+1,0);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i==find(i)&&!cycle[i]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}