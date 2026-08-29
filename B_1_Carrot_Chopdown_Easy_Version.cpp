#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>arr1(m+1,0);
        for(int i=0;i<n;i++){
            arr1[arr[i]]++;
        }
        int ans=n;
        int sum=0;
        for(int i=1;i<=m;i++){
            int rem=n-sum;
            if(i*2<=m){
                rem+=arr1[i*2];
            }
            sum+=arr1[i];
            ans=max(ans,rem);
        }
        cout<<ans<<endl;
    }
    return 0;
}