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
        if(n<4){
            cout<<-1<<endl;
            continue;
        }
        if(n==4){
            cout<<"3 1 4 2"<<endl;
            continue;
        }
        int i;
        for(i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
        i-=2;
        if(i==n){
            cout<<i-3<<" ";
            i-=3;
            cout<<i+2<<" ";
            i+=2;
            i-=4;
            while(i>0){
                cout<<i<<" ";
                i-=2;
            }
            cout<<endl;
        }else{
            i-=3;
            cout<<i<<" ";
            i+=4;
            cout<<i<<" ";
            i-=2;
            cout<<i<<" ";
            i-=4;
            while(i>0){
                cout<<i<<" ";
                i-=2;
            }
            cout<<endl;
        }
    }
    return 0;
}