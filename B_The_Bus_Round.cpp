#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a,b,c;
        cin>>a>>b>>c;

        // int k = a+1;
        // long long ans = 0;
        
        // while(k <= b) {
        //     ans += ()
        // }
        int total=c*(c-1)/2;
        int val0=a/c;
        int valn=b/c;
        int ans=(valn-val0+1)*total;
        int arem=a%c;
        int brem=b%c;
        ans-=(arem*(arem+1)/2);
        ans-=(total-brem*(brem+1)/2);
        cout<<ans<<endl;
    }
    return 0;
}