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
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    unordered_map<int,vector<int>>adj;
    queue<pair<int,int>>q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==-1){
            q.push({i,0});
        }
        adj[x].push_back(i);
    }
    int ans=0;
    while(!q.empty()){
        auto [node,depth]=q.front();
        q.pop();
        ans=max(ans,depth);
        for(int child:adj[node]){
            q.push({child,depth+1});
        }
    }
    cout<<ans+1<<endl;
    return 0;
}