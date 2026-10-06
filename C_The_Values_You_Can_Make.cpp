#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>dp(k+1,vector<int>(k+1,0));
    dp[0][0]=1;
    for(int x:arr){
        for(int i=k;i>=0;i--){
            for(int j=k;j>=0;j--){
                if(!dp[i][j]) continue;
                if(i+x<=k)dp[i+x][j]=1;
                if(j+x<=k)dp[i][j+x]=1;
            }
        }
    }
    set<int>ans;
    for(int j=0;j<=k;j++){
        if(dp[j][k-j]){
            ans.insert(j);
        }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}