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
    int n,d;
    cin>>n>>d;
    Rank.resize(n+1,0);
    parent.resize(n+1,0);
    for(int i=1;i<n+1;i++){
        parent[i]=i;
    }
    vector<int>ans;
    int cnt=0;
    for(int i=0;i<d;i++){
        int u,v;
        cin>>u>>v;
        if(find(u)==find(v))cnt++;
        else Union(u,v);
        unordered_map<int,int>mp;
        for(int i=0;i<=n;i++){
            mp[find(i)]++;
        }
        int temp=0;
        vector<int>vec;
        for(auto it:mp){
           vec.push_back(it.second);
        }
        sort(vec.rbegin(),vec.rend());
        for(int i=0;i<min((int)vec.size(),cnt+1);i++){
            temp+=vec[i];
        }
        ans.push_back(temp-1);
    }
    for(auto it:ans){
        cout<<it<<endl;
    }
    return 0;
}