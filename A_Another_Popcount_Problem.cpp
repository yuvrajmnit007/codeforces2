#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >>t;
    while (t--){
        int n,k;
        cin>>n>>k;
        int ans=0;
        for(int bit=0;bit<=20;bit++){
            int val=1LL<<bit;
            if (val>n) break;
            int p=min(k,n/val);
            ans+=p;
            n-=p*val;
        }
        cout<<ans<<endl;
    }
    return 0;
}