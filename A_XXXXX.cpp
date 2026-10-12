#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,x;
        cin>>n>>x;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>pre(n+1,0),suf(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+arr[i-1];
        }
        for(int i=n-1;i>=0;i--){
            suf[i]=suf[i+1]+arr[i];
        }
        int ans=-1;
        for(int i=0;i<=n;i++){
            if(pre[i]%x!=0)ans=max(ans,i);
            if(suf[i]%x!=0)ans=max(ans,n-i);
        }
        cout<<ans<<endl;
    }
    return 0;
}