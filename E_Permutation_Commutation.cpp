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
        vector<int>a(n+1),b(n+1);
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            mp[a[i]]=i;
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        
    }
    return 0;
}