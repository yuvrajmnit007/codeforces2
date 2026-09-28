#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,a,b;
        cin>>n>>a>>b;
        if(a==n&&b==n){
            cout<<"Yes\n";
            continue;
        }
        if(n-(a+b)>1){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}