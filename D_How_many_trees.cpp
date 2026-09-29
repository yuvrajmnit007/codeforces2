#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>fact(36,1);
int MOD=9*1e18;
int power(int base,int expo){
    int ans=1;
    while(expo>0){
        if(expo%2==1){
            ans=(ans*base)%MOD;
        }
        base=(base*base)%MOD;
        expo/=2;
    }
    return ans;
}
int ncr(int a,int b){
    if(a<b)return 0;
    int val=(power(fact[a-b],MOD-2)*power(fact[b],MOD-2))%MOD;
    return (fact[a]*val)%MOD;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=1;i<=35;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    int n,k;
    cin>>n>>k;
    int val=(ncr(2*n,n)*power(n+1,MOD-2));
    int val2=(ncr(2*(k-1),k-1)*power(k,MOD-2))%MOD;
    cout<<val-val2<<endl;
    return 0;
}