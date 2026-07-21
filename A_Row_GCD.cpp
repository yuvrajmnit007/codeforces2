#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    vector<int>b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int g=0;
    for(int i=1;i<n;i++){
        g=__gcd(g,abs(a[i]-a[i-1]));
    }
    for(int i=0;i<m;i++){
        cout<<__gcd(g,a[n-1]+b[i])<<" ";
    }
    cout<<endl;
    return 0;
}