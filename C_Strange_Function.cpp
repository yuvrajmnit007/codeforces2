#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=1e9+7;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int lcm=1;
        int i=2;
        int ans=0;
        while(1){
            int a=n/lcm;
            int hcf=__gcd(lcm,i);
            lcm=lcm*i/hcf;
            int b=n/lcm;
            ans+=(a-b)*i;
            ans%=MOD;
            if(lcm>n)break;
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}