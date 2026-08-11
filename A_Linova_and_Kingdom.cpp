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
vector<int>height,sz;
unordered_map<int,vector<int>>adj;
int dfs(int parent,int node){
    height[node]=height[parent]+1;
    sz[node]=1;
    for(auto it:adj[node]){
        if(it==parent)continue;
        sz[node]+= dfs(node,it);;
    }
    return sz[node];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    height.resize(n+1,0);
    sz.resize(n+1,0);
    for(int i=0;i<n-1;i++){
        int l,r;
        cin>>l>>r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    dfs(0,1);
    vector<int>diff;
    for(int i=1;i<=n;i++){
        diff.push_back(sz[i]-height[i]);
    }
    sort(diff.rbegin(),diff.rend());
    int ans=0;
    for(int i=0;i<n-k;i++){
        ans+=diff[i];
    }
    cout<<ans<<endl;
    return 0;
}