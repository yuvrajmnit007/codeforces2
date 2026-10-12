#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,x,y;
        cin>>n>>x>>y;
        vector<int>arr(n);
        int ans=0;
        for(auto &it:arr){
            cin>>it;
            ans+=(it%2);
        }
        int alice=x,bob=x+3;
        if((ans+x%2)%2==y%2){
            cout<<"Alice"<<endl;
        }else{
            cout<<"Bob"<<endl;
        }
    }
    return 0;
}