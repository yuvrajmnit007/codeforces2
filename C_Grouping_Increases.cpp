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
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int a=1e18,b=1e18,ans=0;
        for(int i=0;i<n;i++){
            if(a>b)swap(a,b);
            if(arr[i]<=a){
                a=arr[i];
            }else if(arr[i]<=b){
                b=arr[i];
            }else{
                a=arr[i];
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}