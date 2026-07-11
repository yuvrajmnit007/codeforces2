#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ans=n*(n-1)*(n-3)*(n-2)*(n-4)/120;
    cout<<ans*n*(n-1)*(n-3)*(n-2)*(n-4)<<endl;
    return 0;
}