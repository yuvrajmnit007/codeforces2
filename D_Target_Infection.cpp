#include <bits/stdc++.h>
using namespace std;
#define int long long

int count_inf(int x, int n, const vector<pair<int, int>>& a, const vector<int>& pref) {
    if (x <= 0) return 0;
    int low = 0, high = n - 1, idx = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid].first <= x) {
            idx = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (idx == -1) return 0;
    return pref[idx] + max(0LL, min(a[idx].second, x) - a[idx].first + 1);
}

int get_f(int s, int m, int n, const vector<pair<int, int>>& a, const vector<int>& pref) {
    return count_inf(s + m - 1, n, a, pref) - count_inf(s - 1, n, a, pref);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int, int>> a(n);
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            pref[i + 1] = pref[i] + (a[i].second - a[i].first + 1);
        }
        if (k == 0) {
            cout << a[n - 1].second + 1 << "\n";
            continue;
        }
        int opt_s = -1;
        for (int i = 0; i < n; i++) {
            if (get_f(a[i].first, m, n, a, pref) >= k) {
                opt_s = a[i].first;
                break;
            }
        }
        if (opt_s == -1) {
            cout << -1 << "\n";
            continue;
        }
        int low = opt_s, high = a[n - 1].second + 2, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cur = get_f(mid, m, n, a, pref);
            if (cur == k) {
                ans = mid;
                break;
            }
            if (cur > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}