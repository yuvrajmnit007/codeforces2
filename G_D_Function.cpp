#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=1e9+7;
int f(int base,int expo){
    int res=1;
    while(expo>0){
        if(expo%2==1){
            res=(res*base)%MOD;
        }
        base=(base*base)%MOD;
        expo/=2;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int l,r,k;
        cin>>l>>r>>k;
        if(k>=10){
            cout<<0<<endl;
        }else{
            int mx=9/k;
            int val=f(mx+1,l);
            int val1=f(mx+1,r);
            cout<<(val1-val+MOD)%MOD<<endl;
        }
    }
    return 0;
}