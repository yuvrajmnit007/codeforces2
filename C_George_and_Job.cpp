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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>arr(n);
    vector<int>pre(n+1,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        pre[i+1]=pre[i]+arr[i];
    }
    if(m*k==n){
        cout<<pre[n]<<endl;
    }else{
        
    }
    // priority_queue<int>pq;
    // for(int sz=0;sz<m;sz++){
    //     for(int i=1;i+sz<=n;i++){
    //         pq.push(pre[i+sz]-pre[i-1]);
    //     }
    // }
    // int ans=0;
    // while(!pq.empty()&&k--){
    //     ans+=pq.top();
    //     pq.pop();
    // }
    // cout<<ans<<endl;
    return 0;
}