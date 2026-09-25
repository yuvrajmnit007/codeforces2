#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a,b,c;
        cin>>a>>b>>c;
        a+=(c%2);
        if(a>b){
            cout<<"First\n";
        }else{
            cout<<"Second\n";
        }
    }
    return 0;
}