#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>vec1,vec2;
map<pair<int,int>,int>dp;
int f(int idx ,int total){
    if(idx==(int)vec1.size()){
        return 0;
    }
    if(dp.count({idx,total}))return dp[{idx,total}];
    int take=-1e9,nottake=-1e9;
    if(vec1[idx]<=total){
        take=vec2[idx]+f(idx+1,total-vec1[idx]);
    }
    nottake=f(idx+1,total);
    return dp[{idx,total}]=max(take,nottake);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vec1.resize(n);
    vec2.resize(n);
    for(int i=0;i<n;i++)cin>>vec1[i];
    for(int i=0;i<n;i++)cin>>vec2[i];
    cout<<f(0,k)<<endl;
    return 0;
}