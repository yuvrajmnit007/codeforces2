#include <bits/stdc++.h>
#define int long long
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin>>n;
        std::vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            std::cin>>arr[i];
        }
        std::vector<int>dp(n+1,0);
        dp[n]=arr[n];
        for(int i=n-1;i>=1;i--){
            if(i+arr[i]<=n)dp[i]=arr[i]+std::max(dp[i],dp[i+arr[i]]);
            else dp[i]=std::max(dp[i],arr[i]);
        }
        std::cout<<*std::max_element(dp.begin(),dp.end())<<'\n';
    }
    return 0;
}