#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=998244353;
int power(int base,int expo){
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
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>vec=arr;
        sort(arr.begin(),arr.end());
        int fact=1;
        for(int i=1;i<n;i++){
            fact=(fact*i)%MOD;
        }
        int ans=0;
        int sum=0;
        for(int i=n-1;i>=0;i--){
            int cnt=n-1-i;
            if(cnt>0){
                int total=(sum%MOD-(cnt%MOD)*(arr[i]%MOD))%MOD;
                if(total<0)total+=MOD;
                int ways=fact*power(cnt,MOD-2)%MOD;
                ans=(ans+ways*total)%MOD;
            }
            sum=(sum+arr[i])%MOD;
        }
        cout<<ans<<'\n';
    }
    return 0;
}