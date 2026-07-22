#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>dp;
int f(int turn,int idx,vector<int>&arr){
    int  n=arr.size();
    if(idx>=arr.size())return 0;
    if(dp[idx][turn]!=-1)return dp[idx][turn];
    int take1=1e18;int take2=1e18;
    if(turn==0){
        take1=(arr[idx]==1)+f(1,idx+1,arr);
        if(idx+1<n){
            take2=(arr[idx]==1)+(arr[idx+1]==1)+f(1,idx+2,arr);
        }
    }else{
        take1=f(0,idx+1,arr);
        if(idx+1<n){
            take2=f(0,idx+2,arr);
        }
    }
    return dp[idx][turn]=min(take1,take2);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        dp.clear();
        dp.resize(n+1,vector<int>(2,-1));
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<f(0,0,arr)<<endl;
    }
    return 0;
}