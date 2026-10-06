#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans=0;
        if(n<=2*(k-1)){
            for(int i=0;i<(n+1)/2;i++){
                if(max(i,n-i-1)>=k-1){
                    ans+=max(arr[i],arr[n-i-1]);
                }
            }
            cout<<ans<<endl;
        }else{
            for(int i=0;i<(n-k+1);i++){
                if(i<k-1){
                    ans+=max(arr[i],arr[n-i-1]);
                }else{
                    ans+=arr[i];
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}