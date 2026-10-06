#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> parent, Rank;
vector<set<int>>adj;
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (Rank[x] < Rank[y]) {
        parent[x] = y;
    } else if (Rank[x] > Rank[y]) {
        parent[y] = x;
    } else {
        parent[y] = x;
        Rank[x]++;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        parent.assign(n + 1, 0);
        Rank.assign(n + 1, 0);
        iota(parent.begin(), parent.end(),0);
        adj.assign(n + 1, set<int>());
        for (int i = 1; i <= n; i++) {
            int v;
            cin >> v;
            adj[i].insert(v);
            adj[v].insert(i);
            Union(i, v);
        }
        map<int,vector<int>>mp;
        for(int i=1;i<=n;i++){
            mp[find(i)].push_back(i);
        }
        int cnt=0;
        int temp=0;
        for(auto &it:mp){
            bool ok=true;
            for (int u:it.second){
                if(adj[u].size()<2){
                    ok=false;
                    break;
                }
            }
            if(ok){
                cnt++;
            }else{
                temp++;
            }
        }
        if(temp>0){
            cnt++;
        }
        cout<<cnt<<" "<<mp.size()<<endl;
    }
    return 0;
}