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
    int t=1;
    while (t--) {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        unordered_map<int,int>dp;
        for(int i=0;i<n;i++){
            dp[arr[i]]=max(dp[arr[i]],dp[arr[i]-1]+1);
        }
        int ans=0;
        int val=0;
        for(auto it:dp){
            if(it.second>ans){
                ans=it.second;
                val=it.first;
            }
        }
        vector<int>rand;
        for(int i=n-1;i>=0;i--){
            if(arr[i]==val){
                rand.push_back(i+1);
                val--;
            }
        }
        cout<<ans<<endl;
        for(int i=rand.size()-1;i>=0;i--){
            cout<<rand[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}






// using namespace std;
// #define int long long
// map<pair<int,int>,int>dp;
// vector<int>ans;
// int f(int idx,vector<int>&nums,int prev){
//     int n=nums.size();
//     if(idx>=n){
//         return 0;
//     }
//     auto it=dp.find({idx,prev});
//     if(it!=dp.end())return it->second;
//     int take=0,nottake=0;
//     if(prev==-1||nums[idx]==nums[prev]+1){
//         take=1+f(idx+1,nums,idx);
//     }
//     nottake=f(idx+1,nums,prev);
//     return dp[{idx,prev}]=max(take,nottake);

// }
// void f1(int idx,vector<int>&nums,int prev){
//     int n=nums.size();
//     if(idx>=n){
//         return ;
//     }
//     if(prev==-1||(nums[idx]==nums[prev]+1&&dp[{idx,prev}]==1+dp[{idx+1,idx}])){
//         ans.push_back(idx);
//         f1(idx+1,nums,idx);
//         return;
//     }
//     f1(idx+1,nums,prev);
// }
// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t=1;
//     while (t--) {
//         dp.clear();
//         ans.clear();
//         int n;
//         cin>>n;
//         vector<int>arr(n);
//         for(int i=0;i<n;i++){
//             cin>>arr[i];
//         }
//         cout<<f(0,arr,-1)<<endl;
//         f1(0,arr,-1);
//         for(auto it:ans){
//             cout<<it+1<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }