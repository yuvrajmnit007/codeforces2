#include <bits/stdc++.h>
using namespace std;
#define int long long
int power(int base,int expo){
    int res=1;
    while(expo>0){
        if(expo%2==1){
            res*=base;
        }
        base*=base;
        expo/=2;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin>>a>>b;
        int d=0;
        while(a>0||b>0){
            if(a%2==b%2){
                d++;
                a/=2;
                b/=2;
            }else break;
        }
        cout<<power(2,d)<<endl;
    }
    return 0;
}