#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=998244353;
vector<int>fact(300001,1);
vector<bool>isprime(300002,true);
vector<int>primes;
int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}
int ncr(int n,int r){
    if(r>n)return 0;
    if(r==0||r==n)return 1;
    return (fact[n]*power(fact[n-r]*fact[r]%MOD,MOD-2))%MOD;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    fact[0]=1;
    for(int i=1;i<=300000;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=300001;i++){
        if(isprime[i]){
            primes.push_back(i);
            for(int j=i*i;j<=300001;j+=i){
                isprime[j]=false;
            }
        }
    }
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        map<int,int>mp2;
        for(int x:arr){
            int temp=x;
            for(int p:primes){
                if(p*p>temp)break;
                if(temp%p==0){
                    mp2[p]++;
                    while(temp%p==0)temp/=p;
                }
            }
            if(temp>1)mp2[temp]++;
        }
        int ans=0;
        int total=ncr(n,k);
        for(auto it:mp2){
            int val=it.first;
            int val2=it.second;
            int ways=(total-ncr(n-val2,k)+MOD)%MOD;
            ans=(ans+(val%MOD)*ways)%MOD;
        }
        cout<<ans<<"\n";
    }
    return 0;
}