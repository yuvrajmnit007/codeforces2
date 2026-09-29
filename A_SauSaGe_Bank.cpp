#include <bits/stdc++.h>
using namespace std;
#define int long long
int power(int base,int expo){
    int ans=1;
    while(expo>0){
        if(expo%2==1){
            ans*=base;
        }
        base*=base;
        expo/=2;
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        int val=n-k;
        cout<<power(2,val+1)+2*(k-1)<<endl;
    }
    return 0;
}