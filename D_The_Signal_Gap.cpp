#include <bits/stdc++.h>
using namespace std;
#define int long long
void print128(__int128 x) {
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    if (x > 9) print128(x / 10);
    cout << (char)('0' + (x % 10));
}
void solve() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int &i : v) cin >> i;

    __int128 ans = 0;
    vector<int> suf(n,0);

    suf[n-1] = v[n-1];
    
    unordered_map<int,int> mp;
    mp[v[n-1]]++;
    for(int i=n-2; i>=0; i--) {
        mp[v[i]]++;

        int val = 0, val2 = 0, val3 = 0;

        if(mp.find(v[i]+1) != mp.end()) val=mp[v[i]+1];
        if(mp.find(v[i]-1) != mp.end()) val2=mp[v[i]-1];
        if(mp.find(v[i]) != mp.end()) val3=mp[v[i]];

        ans += (suf[i+1]-(n-i-1)*v[i]);
        ans -= ((val));
        ans += val2;

        suf[i]=suf[i+1]+v[i];
    }

    if (ans == 0) {
        cout << 0 << "\n";
    } else {
        print128(ans);
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}