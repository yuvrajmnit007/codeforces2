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
        return;
    }
    if(Rank[x_parent]>Rank[y_parent]){
        parent[y_parent]=x_parent;
    }else if(Rank[x_parent]<Rank[y_parent]){
        parent[x_parent]=y_parent;
    }else{
        parent[x_parent]=y_parent;
        Rank[y_parent]++;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        Rank.clear();
        parent.clear();
        Rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            Union(i,arr[i]-1);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[find(i)]++;
        }
        for(int i=0;i<n;i++){
            int val=find(i);
            cout<<mp[val]<<" ";
        }
        cout<<endl;
    }
    return 0;
}