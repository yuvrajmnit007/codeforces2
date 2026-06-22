#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+s[i]-'0';
        }
        unordered_map<int,int>mp;
        for(int i=0;i<=n;i++){
            mp[pre[i]-i]++;
        }
        int ans=0;
        for(auto it:mp){
            ans+=(it.second)*(it.second-1)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}