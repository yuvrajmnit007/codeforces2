
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
        if((n&k)!=k){
            cout<<-1<<endl;
            continue;
        }
        int ans=n;
        bool ok=true;
        for(int i=0;i<61;i++){
            if((n&(1LL<<i))&&!(k&(1LL<<i))){
                int temp=((n>>(i+1))+1)<<(i+1);
                ans=max(ans,temp);
            }
        }
        int x=n;
        for(int i=0;i<61;i++){
            if(ans&(1LL<<i)){
                if(!(k&(1LL<<i))&&(n&(1LL<<i))){
                    ok=false;
                    break;
                }
            }
        }
        int a=n,b=ans;
        while(a<b){
            a>>=1;
            b>>=1;
        }
        int shift=0;
        a=n;
        b=ans;
        while(a<b){
            a>>=1;
            b>>=1;
            shift++;
        }
        if((a<<shift)!=k)ok=false;
        if(ok)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
