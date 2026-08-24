#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr={0,1,2,6};
    if(n<=3){
        cout<<arr[n]<<endl;
        return 0;
    }
    if(n%2){
        cout<<n*(n-1)*(n-2)<<endl;
    }else{
        int ans=0;
        for(int i=n;i>=max(n-60,1LL);i--){
            for(int j=i-1;j>=max(i-60,1LL);j--){
                for(int k=j-1;k>=max(j-60,1LL);k--){
                    int lcm=(i*j)/__gcd(i,j);
                    lcm=(lcm*k)/__gcd(lcm,k);
                    ans=max(ans,lcm);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}