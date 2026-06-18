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
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int mn=1e9;
        int ans=0;
        for(int i=0;i<n;i++){
            mn=min(mn,arr[i]);
            ans+=mn;
        }
        cout<<ans<<endl;
    }
    return 0;
}