#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=1e9+7;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<char>> vec(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> vec[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    if(vec[0][0]=='.'){
        dp[0][0]=1;
    }
    for(int i=1;i<n;i++){
        if(vec[0][i]=='.'){
            dp[0][i]=dp[0][i-1];
        }
    }
    for(int i=1;i<n;i++){
        if(vec[i][0]=='.'){
            dp[i][0]=dp[i-1][0];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(vec[i][j]=='.'){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                if(dp[i][j]>=MOD){
                    dp[i][j]-=MOD;
                }
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;
}