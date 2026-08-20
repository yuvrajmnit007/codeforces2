#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0&&k){
            k--;
            ans+=abs(arr[i]);
        }else{
            ans+=arr[i];
        }
        arr[i]=abs(arr[i]);
    }
    if(k%2==1){
        ans-=2*(*min_element(arr.begin(),arr.end()));
    }
    cout<<ans<<endl;
    return 0;
}