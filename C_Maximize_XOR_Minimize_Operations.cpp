#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int s=a+b;
        int temp=a&(~s);
        if(temp==0){
            cout<<s<<" "<<0<<endl;
            continue;
        }
        int y=63-__builtin_clzll(temp);
        int h=~((1LL<<(y+1))-1);
        int l=(1LL<<y)-1;
        int x=(a&h)|(s&l);
        cout<<s<<" "<<a-x<<endl;
    }
    return 0;
}