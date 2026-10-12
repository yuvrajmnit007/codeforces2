#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int plus=0,minus=0;
    for(auto it:s){
        if(it=='+')plus++;
        else minus++;
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        int g= __gcd(a,b);
        int lcm=(a*b)/g;
        if(plus==minus) cout<<"YES"<<endl;
        else if(a==b) cout<<"NO"<<endl;
        else if((abs(plus-minus)%abs(lcm/a-lcm/b)==0)&&((lcm/a+lcm/b)*(abs(plus-minus)/abs(lcm/a-lcm/b))<=(plus+minus))) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}