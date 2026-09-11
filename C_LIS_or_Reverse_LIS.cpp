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
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        int ans=0;
        int cnt=0;
        for(auto it:mp){
            if(it.second>=2){
                ans++;
            }
            if(it.second==1)cnt++;
        }
        cout<<ans+(cnt+1)/2<<endl;
    }
    return 0;
}