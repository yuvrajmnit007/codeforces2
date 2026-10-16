#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin>>a>>b;
        int diff=a-b;
        if(diff<=0){
            cout<<-1<<endl;
        }else{
            cout<<min(diff,b)<<endl;
        }
    }
    return 0;
}