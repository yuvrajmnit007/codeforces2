#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=1e9+7;
int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while (t--) {
        /*
        implementing this logic again and and it is to be remembered for such kinda problems in future
        summation of (ai-aj)^2=n*summation of(ai^2)-(summation of ai)^2
        */
        int n,q;
        cin>>n>>q;
        vector<int>arr(n);
        vector<int>pref(n+1,0);
        vector<int>pref2(n+1,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];    
            pref[i+1]=(pref[i]+arr[i])%MOD;
            pref2[i+1]=(pref2[i]+(arr[i]*arr[i])%MOD)%MOD;
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            l--;
            int len=r-l+1;
            int sum1=pref[r]-pref[l];
            int sum2=pref2[r]-pref2[l];
            int ans=(len*((sum1*sum1)%MOD)%MOD-(len*sum2)%MOD+MOD)%MOD;
            ans=(ans*power(2*len,MOD-2))%MOD;
            cout<<ans<<'\n';
        }
    }
    return 0;
}