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
        int ans=0;
        for(int a=1;a<n;a++){
            for(int b=1;b<n;b++){
                if(a*b>n)break;
                int c=min((n-a*b)/(a+b),k-a-b);
                if(c>=1)ans+=c;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}