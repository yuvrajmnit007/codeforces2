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
    if(node==parent[node])return node;
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
    int t=1;
    while (t--) {
        int n,m,k;
        cin>>n>>m>>k;
        vector<pair<int,int>>vec;
        for(int i=0;i<k;i++){
            int r,c;
            cin>>r>>c;
            vec.push_back({r,c+n});
        }
        parent.clear();
        Rank.clear();
        parent.resize(m+n+1,0);
        Rank.resize(m+n+1,0);
        for(int i=1;i<=m+n;i++){
            parent[i]=i;
        }
        for(auto it:vec){
            if(find(it.first)!=find(it.second))Union(it.first,it.second);
        }
        set<int>st;
        for(int i=1;i<=m+n;i++){
            st.insert(find(i));
        }
        cout<<st.size()-1<<endl;
    }
    return 0;
}