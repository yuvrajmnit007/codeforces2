#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string s;
    cin >> s;

    // Initial inversion count
    long long inv = 0;
    long long ones = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            ones++;
        } else {
            inv += ones;
        }
    }

    // Output for state 0
    vector<long long> ans;
    ans.reserve(n + 1);
    ans.push_back(inv);

    // Group into alternating runs: type (0 or 1) and count
    // We only care about the region between the first 1 and the last 0.
    int first_one = 0;
    while (first_one < n && a[first_one] == 0) first_one++;

    int last_zero = n - 1;
    while (last_zero >= 0 && a[last_zero] == 1) last_zero--;

    if (first_one > last_zero) {
        // Already sorted
        for (int i = 0; i < n; ++i) ans.push_back(0);
        for (int i = 0; i <= n; ++i) {
            cout << ans[i] << (i == n ? "" : " ");
        }
        cout << "\n";
        return;
    }

    // Structure for Doubly Linked List of blocks
    struct Block {
        int type; // 0 or 1
        int count;
        int prev, next;
    };

    vector<Block> blocks;
    blocks.reserve(2 * n + 5);

    auto add_block = [&](int type, int count) {
        int id = blocks.size();
        blocks.push_back({type, count, -1, -1});
        return id;
    };

    int head = -1, tail = -1;
    auto append_node = [&](int id) {
        if (head == -1) {
            head = tail = id;
        } else {
            blocks[tail].next = id;
            blocks[id].prev = tail;
            tail = id;
        }
    };

    for (int i = first_one; i <= last_zero; ) {
        int j = i;
        while (j <= last_zero && a[j] == a[i]) j++;
        append_node(add_block(a[i], j - i));
        i = j;
    }

    auto remove_node = [&](int u) {
        int p = blocks[u].prev;
        int nxt = blocks[u].next;
        if (p != -1) blocks[p].next = nxt;
        else head = nxt;
        if (nxt != -1) blocks[nxt].prev = p;
        else tail = nxt;
    };

    for (int step = 0; step < n; ++step) {
        if (inv == 0) {
            ans.push_back(0);
            continue;
        }

        char op = s[step];

        if (op == '1') {
            // Bubble: A '1' leaps to the right across each block of '0's
            // Each block of 0s reduces inv by its count.
            // A 1 is transferred from the preceding 1-block to the succeeding 1-block.
            int cur = head;
            while (cur != -1) {
                if (blocks[cur].type == 0) {
                    inv -= blocks[cur].count;

                    int p = blocks[cur].prev;
                    int nxt = blocks[cur].next;

                    blocks[p].count--;
                    if (nxt != -1) {
                        blocks[nxt].count++;
                    }
                }
                cur = blocks[cur].next;
            }
        } else {
            // Reverse Bubble: A '0' leaps to the left across each block of '1's
            // Each block of 1s reduces inv by its count.
            // A 0 is transferred from the succeeding 0-block to the preceding 0-block.
            int cur = head;
            while (cur != -1) {
                if (blocks[cur].type == 1) {
                    inv -= blocks[cur].count;

                    int p = blocks[cur].prev;
                    int nxt = blocks[cur].next;

                    blocks[nxt].count--;
                    if (p != -1) {
                        blocks[p].count++;
                    }
                }
                cur = blocks[cur].next;
            }
        }

        // Clean up empty blocks and merge identical adjacent blocks
        int cur = head;
        while (cur != -1) {
            int nxt = blocks[cur].next;
            if (blocks[cur].count <= 0) {
                remove_node(cur);
            }
            cur = nxt;
        }

        // Merge adjacent blocks of the same type
        cur = head;
        while (cur != -1) {
            int nxt = blocks[cur].next;
            if (nxt != -1 && blocks[cur].type == blocks[nxt].type) {
                blocks[cur].count += blocks[nxt].count;
                remove_node(nxt);
            } else {
                cur = nxt;
            }
        }

        // Trim leading 0s and trailing 1s
        while (head != -1 && blocks[head].type == 0) {
            remove_node(head);
        }
        while (tail != -1 && blocks[tail].type == 1) {
            remove_node(tail);
        }

        if (head == -1) inv = 0;
        inv = max(0LL, inv);
        ans.push_back(inv);
    }

    for (int i = 0; i <= n; ++i) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}