#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int>vec(n);
        vector<int>pre(n+1,0);
        for(int i=0;i<n;i++){
            cin>>vec[i];
            pre[i+1]=(pre[i]+vec[i])%k;
        }
        int ans=0;
        map<int,int>mp;
        for(int i=k+1;i<=n;i++){
            mp[pre[i-k-1]]++;
            ans+=mp[pre[i]];
        }
        cout<<ans<<endl;
    }
    return 0;
}