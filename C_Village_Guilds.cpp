#include <bits/stdc++.h>
using namespace std;
#define int long long
int dfs(int node, int depth,vector<vector<int>>&adj,int& ans){
    int mx1=-1,mx2=-1;
    for(int it:adj[node]){
        int child=dfs(it,depth+1,adj,ans);
        if(child>=mx1){
            mx2=mx1;
            mx1=child;
        }else if(child>mx2){
            mx2=child;
        }
    }
    if(mx2!=-1){
        ans+=(mx2-depth);
    }
    return (mx1==-1)?depth:mx1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>arr(n-1);
        for(int i=0;i<n-1;i++){
            cin>>arr[i];
        }
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n-1;i++){
            adj[arr[i]].push_back(i+2);
        }
        int ans=n;
        dfs(1,0,adj,ans);
        cout<<ans<<endl;
    }
    return 0;
}