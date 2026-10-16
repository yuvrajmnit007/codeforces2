#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            arr[i]%=2;
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            int j=i+1;
            while(j<n&&arr[j]==arr[i]){
                j++;
            }
            ans+=j-i-1;
            i=j-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}