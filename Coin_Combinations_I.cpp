#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=1e9+7;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<int>dp(k+1,0);
    dp[0]=1;
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(arr[j]>i)break;
            dp[i]=dp[i]+dp[i-arr[j]];
            if(dp[i]>=MOD)dp[i]-=MOD;
        }
    }
    cout<<dp[k]<<endl;
    return 0;
}