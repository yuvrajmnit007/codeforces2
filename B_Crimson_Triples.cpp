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
        int ans=0;
        for(int i=1;i<=n;i++){
            int temp=n/i;
            ans+=(temp*temp);
        }
        cout<<ans<<endl;
    }
    return 0;
}