#include <bits/stdc++.h>
using namespace std;
#define int long long
string l,r;
int dp[15][2][2];
int dfs(int pos,int tightl,int tightr){
    if(pos==l.size())return 0;
    int &res=dp[pos][tightl][tightr];
    if(res!=-1)return res;
    int low=tightl?l[pos]-'0':0;
    int hi=tightr?r[pos]-'0':9;
    res=1e18;
    for(int i=low;i<=hi;i++){
        int temp=(i==l[pos]-'0')+(i==r[pos]-'0');
        res=min(res,temp+dfs(pos+1,tightl&&(i==low),tightr&&(i==hi)));
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin>>l>>r;
        memset(dp,-1,sizeof(dp));
        cout<<dfs(0,1,1)<<endl;
    }
    return 0;
}