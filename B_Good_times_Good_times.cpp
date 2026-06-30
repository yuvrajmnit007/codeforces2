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
        cin >> n;
        string s = to_string(n);
        string k = "1";
        for (int i = 0; i < s.size() - 1; i++) {
            k += '0';
        }
        k += '1';
        cout << k << '\n';
    }
    return 0;
}