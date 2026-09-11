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
        map<int,int>mp;
        int mx=-1e18;
        vector<int>arr(n),brr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            cin>>brr[i];
        }
        for(int i=0;i<n;i++){
            mx=max(mx,arr[i]-brr[i]);
            mp[arr[i]-brr[i]]++;
        }
        cout<<mp[mx]<<endl;
        for(int i=0;i<n;i++){
            if(arr[i]-brr[i]==mx){
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}