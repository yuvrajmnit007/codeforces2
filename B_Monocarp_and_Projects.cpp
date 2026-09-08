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
        int ans=0;
        int x=b-a;
        for(int i=a;i<=min(x,a+c-1);i++){
            ans+=(x)%i;
        }
        if(a+c-1>x)ans+=(a+c-max(a,x+1))*(x);
        cout<<ans<<endl;
    }
    return 0;
}