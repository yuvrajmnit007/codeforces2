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
        int diff=b-a;
        if(diff>=2){
            cout<<-1<<endl;
        }else if(diff==1){
            cout<<a+1<<endl;
        }else if(diff%2==0){
            cout<<a<<endl;
        }else{
            cout<<a+1<<endl;
        }
    }
    return 0;
}