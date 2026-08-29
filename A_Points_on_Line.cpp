#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=INT_MAX;
vector<int>fact;
int power(int base,int exp){
    int ans=1;
    while(exp>0){
        if(exp%2==1){
            ans*=base;
            ans%=MOD;
        }
        base*=base;
        base%=MOD;
        exp/=2;
    }
    return ans%MOD;
}
int ncr(int n,int r){
    if(r>n)return 0;
    else{
        int val=fact[n];
        int val1=fact[n-r];
        int val2=fact[r];
        val1=(val1*val2)%MOD;
        val1=power(val1,MOD-2);
        return (val*val1)%MOD;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // fact.resize(1e5+1,0);
    // int val=1;
    // fact[0]=1;
    // for(int i=1;i<=1e5;i++){
    //     val*=i;
    //     val%=MOD;
    //     fact[i]=val;
    // }
    int n,d;
    cin>>n>>d;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        auto it=upper_bound(arr.begin(),arr.end(),arr[i]+d)-arr.begin();
        // if(it>=n)it--;
        // if(arr[it]>arr[i]+d)it--;
        // //cout<<it-i<<endl;
        // ans+=(ncr(it-i,2));
        int val=it-i-1;
        ans+=(val)*(val-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}