#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,m,k;
        cin>>n>>m>>k;
        int temp=n;
        for(int i=n;i>m;i--){
            cout<<i<<" ";
        }
        for(int i=1;i<=m;i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}