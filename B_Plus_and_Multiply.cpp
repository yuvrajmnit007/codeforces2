#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,a,b;
        cin>>n>>a>>b;
        if(a==1){
            if((n-1)%b==0){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
            continue;
        }
        bool ans=false;
        int cur=1;
        while(cur<=n){
            if(cur%b==n%b){
                ans = true;
                break;
            }
            if(cur>n/a) break;
            cur *= a;
        }
        if(ans){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}