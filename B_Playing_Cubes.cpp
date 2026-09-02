#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    cout<<max(n,m)-1<<" "<<min(n,m)<<endl;
    return 0;
}