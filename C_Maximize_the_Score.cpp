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
vector<int>dp;
int f(int idx,vector<int>&arr,vector<pair<int,int>>&vec){
    if(idx==arr.size())return 0;
    if(dp[idx]!=-1)return dp[idx];
    int ans=1+f(idx+1,arr,vec);
    int r=vec[arr[idx]].second;
    if(r!=-1){
        ans=max(ans,(r-idx+1)*(r-idx+1)+f(r+1,arr,vec));
    }
    return dp[idx]=ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>arr(2*n);
        vector<pair<int,int>>vec(n+1,{-1,-1});
        for(int i=0;i<2*n;i++){
            cin>>arr[i];
            if(vec[arr[i]].first==-1){
                vec[arr[i]].first=i;
            }
            else vec[arr[i]].second=i;
        }
        dp.clear();
        dp.resize(2*n+1,-1);
        cout<<f(0,arr,vec)<<endl;
    }
    return 0;
}