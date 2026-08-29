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
    if(x_parent==y_parent){
        return;
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
    parent.resize(n+1,0);
    iota(parent.begin(),parent.end(),0);
    Rank.resize(n+1,0);
    while(m--){
        int k;
        cin>>k;
        vector<int>vec(k);
        for(int i=0;i<k;i++){
            cin>>vec[i];
        }
        if(k<=1){
            continue;
        }else{
            for(int i=1;i<k;i++){
                Union(vec[i],vec[i-1]);
            }
        }
    }
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        mp[find(i)]++;
    }
    for(int i=1;i<=n;i++){
        cout<<mp[find(i)]<<" ";
    }
    cout<<endl;
    return 0;
}