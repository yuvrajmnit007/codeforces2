#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,x,m;
        cin>>n>>x>>m;
        int l=x,r=x;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            if(max(l,a)<=min(r,b)){
                l=min(l,a);
                r=max(r,b);
            }
        }
        cout<<r-l+1<<endl;
    }
    return 0;
}