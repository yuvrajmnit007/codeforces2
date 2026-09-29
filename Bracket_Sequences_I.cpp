#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=1e9+7;
vector<int>fact(1e6+1,1);
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
    for(int i=1;i<=1e6;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    int n;
    cin>>n;
    if(n%2==1){
        cout<<0<<endl;
        return 0;
    }
    int k=n/2;
    cout<<(ncr(n,k)*power(k+1,MOD-2))%MOD<<endl;
    return 0;
}