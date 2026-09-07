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
        int ans=1e18;
        for(int i=1;i<n;i++){
            ans=min(ans,max(arr[i],arr[i-1]));
        }
        cout<<ans-1<<endl;
    }
    return 0;
}