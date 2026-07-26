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
bool check(int m,int n,vector<vector<int>>& arr){
    int cur=1;
    for(int j=1;j<=m;j++){
        while(cur<=n){
            int l=arr[cur][0];
            int r=arr[cur][1];
            int u=arr[cur][2];
            int v=arr[cur][3];
            bool ok_left=(j<l||j>r);
            int right_rank=m-j+1;
            bool ok_right=(right_rank<u||right_rank>v);
            if(ok_left&&ok_right){
                break;
            }
            cur++;
        }
        if(cur>n) return false;
        cur++;
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<vector<int>>arr(n+1);
        for(int i=1;i<=n;i++){
            int l,r,u,v;
            cin>>l>>r>>u>>v;
            arr[i]={l,r,u,v};
        }
        int ans=0;
        for(int m=n;m>=1;m--){
            if(check(m,n,arr)){
                ans=m;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}