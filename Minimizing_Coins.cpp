#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> dp;
int f(int target,vector<int>&vec){
    if(target==0)return 0;
    if(dp[target]!=-1)return dp[target];
    int ans=1e9;
    for(auto coin:vec){
        if(coin<=target){
            ans=min(ans,1+f(target-coin,vec));
        }
    }
    return dp[target]=ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,target;
    cin>>n>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dp.assign(target+1,-1);
    int val=f(target,arr);
    if(val>=1e9)cout<<-1<<endl;
    else cout<<val<<endl;
    return 0;
}