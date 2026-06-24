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
        vector<int>vec(32,0);
        int ans=(1<<31)-1;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            ans&=arr[i];
            for(int j=0;j<32;j++){
                if(arr[i]&1<<j){
                    vec[j]++;
                }
            }
        }
        for(int i=30;i>=0;i--){
            if(k>=n-vec[i]){
                ans|=1<<i;
                k-=(n-vec[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}