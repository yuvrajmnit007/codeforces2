#include<bits/stdc++.h>
using namespace std;
#define int long long
int MOD=998244353;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int ans=0;
    for(int bit=0;bit<31;bit++){
        int odd=0,totalodd=0,totaleven=0,even=0;
        for(int i=0;i<n;i++){
            if((1LL<<bit)&arr[i]){
                swap(odd,even);
                swap(totalodd,totaleven);
                odd++;
                totalodd+=i;
            }else{
                even++;
                totaleven+=i;
            }
            (ans+=(1LL<<bit)*1LL*((((i+1)*odd-totalodd)%MOD)))%=MOD;
        }
    }
    cout<<ans<<"\n";
    return 0;
}