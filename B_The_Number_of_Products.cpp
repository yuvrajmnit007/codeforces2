#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n);
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]<0)cnt++;
    }
    // vector<int>pre(n+2,0);
    // for(int i=0;i<n;i++){
    //     pre[i+1]=pre[i];
    //     if(arr[i]<0){
    //         pre[i+1]++;
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<pre[i]<<" ";
    // }
    // cout<<endl;
    int ans=0;
    int even=1,odd=0;
    bool ok=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0)ok=!ok;
        if(!ok){
            ans+=even;
            even++;
        }else{
            ans+=odd;
            odd++;
        }
    }
    cout<<n*(n+1)/2-ans<<" "<<ans<<endl;
    return 0;
}