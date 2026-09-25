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
        int a;
        int mn=1e18;
        for(int i=0;i<3;i++){
            cin>>a;
            mn=min(mn,a);
        }
        cout<<n-mn<<"\n";
    }
    return 0;
}