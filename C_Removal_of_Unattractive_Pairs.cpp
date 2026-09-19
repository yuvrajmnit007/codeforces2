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
        vector<int>arr(26,0);
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        int mx=-1;
        for(int i=0;i<26;i++){
            mx=max(mx,arr[i]);
        }
        int ans;
        ans=max(n%2,2*mx-n);
        cout<<ans<<"\n";
    }
    return 0;
}