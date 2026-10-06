#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int a=2,b=1;
        for(int i=0;i<=n-1;i++){
            if(i%2){
                cout<<b<<" ";
                b+=2;
            }else{
                cout<<a<<" ";
                a+=2;
            }
        }
        cout<<endl;
    }
    return 0;
}