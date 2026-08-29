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
        sort(arr.begin(),arr.end());
        vector<int>pre(n+1,0);
        pre[1]=arr[0];
        for(int i=1;i<n;i++){
            pre[i+1]=pre[i]+arr[i];
        }
        for(int i=1;i<=min(m,n);i++){
            int l=upper_bound(arr.begin(),arr.end(),arr[i-1]*2)-arr.begin();
            if(arr[l-1]>2*arr[i-1])l--;
            //cout<<l<<" ";
            cout<<pre[l]+n-l<<" ";
        }
        for(int i=n+1;i<=m;i++){
            cout<<pre[n]<<" ";
        }
        cout<<endl;
    }
    return 0;
}