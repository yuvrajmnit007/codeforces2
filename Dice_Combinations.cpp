#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=1e9+7;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>ans(1e6+1,0);
    ans[0]=1;
    ans[1]=1;
    ans[2]=2;
    ans[3]=4;
    ans[4]=8;
    ans[5]=16;
    ans[6]=32;
    int sum=64;
    for(int i=7;i<=1e6;i++){
        ans[i]=(sum-ans[i-7]+MOD)%MOD;
        sum=(sum-ans[i-7]+MOD)%MOD;
        sum=(sum+ans[i])%MOD;
    }
    int n;
    cin>>n;
    cout<<ans[n]<<endl;
    return 0;
}