#include <bits/stdc++.h>
using namespace std;
#define int long long
int const MOD=1000000007;
int bino(int a, int n){
    int result=1;
    while(n>0){
        if(n&1)result=(result*a)%MOD;
        a=(a*a)%MOD;
        n/=2;
    }
    return result%MOD;
}
bool check(int val,int a,int b){
    while(val){
        int digit=val%10;
        if(digit!=a&&digit!=b)return false;
        val/=10;
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,n;
    cin>>a>>b>>n;
    vector<int>factorial(n+1);
    factorial[0]=1;
    for(int i=1;i<=n;i++){
        factorial[i]=(factorial[i-1]*i)%MOD;
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        int sum=i*a+(n-i)*b;
        if(!check(sum,a,b))continue;
        int p=factorial[n],q=factorial[n-i],r=factorial[i];
        int temp=p*bino((q*r)%MOD,MOD-2)%MOD;
        ans=(ans+temp)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}