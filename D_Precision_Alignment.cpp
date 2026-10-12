#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f(int x,vector<int>&arr,vector<int>&vec,int k){
    __int128 temp=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(x<=arr[i])continue;
        if(vec[i]==-1)return false;
        temp+=(__int128)(x-arr[i])+vec[i];
        if(temp>k)return false;
    }
    return true;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n),vec(n);
        int lo=LLONG_MAX,hi=LLONG_MIN;
        for(int i=0;i<n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            arr[i]=a+b+c;
            if(a==b&&b==c){
                vec[i]=-1;
            }else if(a<=b&&b<=c){
                vec[i]=2*min(b-a+1,c-b+1);
            }else {
                vec[i]=0;
            }
            lo=min(lo,arr[i]);
            hi=max(hi,arr[i]);
        }
        hi+=k+1;
        while(lo<hi-1){
            int mid=lo+(hi-lo)/2;
            if(f(mid,arr,vec,k)){
                lo=mid;
            }else hi=mid;
        }
        cout<<lo<<"\n";
    }
    return 0;
}