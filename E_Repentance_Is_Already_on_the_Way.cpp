#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll edgeWeight(ll x, ll y) {
    return (x == y ? 2 : 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<ll> a(n), b(n);

        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        // n = 1: only the vertical edge exists.
        if (n == 1) {
            cout << edgeWeight(a[0], b[0]) << '\n';
            continue;
        }

        vector<ll> top(n - 1);
        vector<ll> bottom(n - 1);
        vector<ll> vertical(n);

        for (int i = 0; i < n; i++) {
            vertical[i] = edgeWeight(a[i], b[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            top[i] = edgeWeight(a[i], a[i + 1]);
            bottom[i] = edgeWeight(b[i], b[i + 1]);
        }

        // Path 0:
        //
        // A0 -> A1 -> ... -> A(n-1)
        //                         |
        // B0 <- B1 <- ... <- B(n-1)
        //
        ll cur = vertical[n - 1];

        for (int i = 0; i < n - 1; i++) {
            cur += top[i];
            cur += bottom[i];
        }

        ll ans = cur;

        // Generate the remaining n-1 Hamiltonian paths.
        for (int i = 0; i < n - 1; i++) {

            // Add vertical edge at column i.
            cur += vertical[i];

            // Remove alternating horizontal edge.
            if (i % 2 == 0)
                cur -= top[i];
            else
                cur -= bottom[i];

            ans = max(ans, cur);
        }

        cout << ans << '\n';
    }

    return 0;
}