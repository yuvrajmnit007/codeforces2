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
        cin >> n >> k;

        vector<int> p(n), q(n);
        for(int i=0; i<n; i++) cin >> p[i];
        for(int i=0; i<n; i++) cin >> q[i];

        int ans = 0;

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++) {
            mp[i+1] = p[i];
        }
        
        for(int i=1; i<=k; i++) {
            int ct = 0;
            for(int)
        }
    }
    return 0;
}