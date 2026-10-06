#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>mp;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    const int N=3e5;
    vector<int>primes;
    vector<bool>isprime(N+1,true);
    isprime[0]=isprime[1]=false;
    for(int i=2;i*i<=N;i++){
        if(isprime[i]){
            for(int j=i*i;j<=N;j+=i){
                isprime[j]=false;
            }
        }
    }
    for(int i=2;i<=N;i++){
        if(isprime[i]){
            primes.push_back(i);
        }
    }
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>arr(n);
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            int g=__gcd(x,arr[i]);
            if(g!=1){
                vec.push_back({g,arr[i]});
            }
        }
        mp.clear();
        for(auto it:vec){
            mp[it.first]+=it.second;
        }
        map<int,int>fact;
        int v=x;
        for(auto it:primes){
            if(it*it>v)break;
            while(v%it==0){
                fact[it]++;
                v/=it;
            }
        }
        if(v>1){
            fact[v]++;
        }
        int ans=0;
        for(auto [p,c]:fact){
            int cur=0;
            for(auto [g,s]:mp){
                if(g%p==0){
                    cur+=s;
                }
            }
            ans=max(ans,cur);
        }
        cout<<ans<<'\n';
    }
    return 0;
}