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
        int ans=0;
        int temp=1;
        while(temp<=n){
            ans++;
            temp*=10;
        }
        temp/=10;
        int k=n/temp;
        cout<<k+(ans-1)*9<<"\n";
    }
    return 0;
}