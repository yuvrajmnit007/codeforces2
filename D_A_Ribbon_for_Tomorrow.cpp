/*
██╗   ██╗██╗   ██╗██╗   ██╗██████╗  █████╗      ██╗
╚██╗ ██╔╝██║   ██║██║   ██║██╔══██╗██╔══██╗     ██║
 ╚████╔╝ ██║   ██║██║   ██║██████╔╝███████║     ██║
  ╚██╔╝  ██║   ██║╚██╗ ██╔╝██╔══██╗██╔══██║██   ██║
   ██║   ╚██████╔╝ ╚████╔╝ ██║  ██║██║  ██║╚█████╔╝
   ╚═╝    ╚═════╝   ╚═══╝  ╚═╝  ╚═╝╚═╝  ╚═╝ ╚════╝
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=998244353;
static const int mx=1e6+5;
int fact[mx];
int power(int base,int exp){
    int res=1;
    base%=MOD;
    while(exp>0){
        if(exp%2==1)res=(res*base)%MOD;
        base=(base*base)%MOD;
        exp/=2;
    }
    return res;
}
int nCr(int n,int r){
    if(r<0||r>n)return 0;
    return fact[n]*power(fact[r],MOD-2)%MOD*power(fact[n-r],MOD-2)%MOD;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0]=1;
    for(int i=1;i<mx;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int a=0,b=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'&&s[i+1]=='0')a++;
            if(s[i]=='1'&&s[i+1]=='1')b++;
        }
        if(a==0&&b==0){
            cout<<1<<endl;
            continue;
        }
        int g0=0,g1=0;
        for(int i=0;i<n;){
            if(s[i]=='0'){
                g0++;
                while(i<n&&s[i]=='0')i++;
            }else{
                g1++;
                while(i<n&&s[i]=='1')i++;
            }
        }
        int ans0=(g0==0)?1:nCr(a+g0-1,a);
        int ans1=(g1==0)?1:nCr(b+g1-1,b);
        cout<<(ans0*ans1)%MOD<<endl;
    }
    return 0;
}