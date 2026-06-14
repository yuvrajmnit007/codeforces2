#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long
const int MOD=1e9+7;
vector<int>seive(500001,0);
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=2;i<500001;i++){
        if(seive[i]==0){
            for(int j=i;j<500001;j+=i){
                if(seive[j]==0)seive[j]=i;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int v;
            cin>>v;
            while(v>1){
                int p=seive[v];
                int cnt=0;
                while(v%p==0){
                    v/=p;
                    cnt++;
                }
                mp[p]+=cnt;
            }
        }
        int ans=1;
        for(auto it:mp){
            ans=(ans*(it.second+1))%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}