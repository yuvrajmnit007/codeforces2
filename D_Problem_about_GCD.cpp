#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int l,r,g;
        cin>>l>>r>>g;
        int a=(l+g-1)/g;
        int b=r/g;
        if(a>b){
            cout<<"-1 -1\n";
            continue;
        }
        bool ok=1;
        for(int i=0;i<300;i++){
            for(int j=0;j<=i;j++){
                if(a+j>b-i+j){
                    break;
                }
                if(__gcd(a+j,b-i+j)==1){
                    cout<<(a+j)*g<<" "<<(b-i+j)*g<<endl;
                    ok=0;
                    break;
                }
            }
            if(!ok)break;
        }
        if(ok)cout<<"-1 -1\n";
    }
    return 0;
}