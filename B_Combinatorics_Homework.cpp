/*
██╗   ██╗██╗   ██╗██╗   ██╗██████╗  █████╗      ██╗
╚██╗ ██╔╝██║   ██║██║   ██║██╔══██╗██╔══██╗     ██║
 ╚████╔╝ ██║   ██║██║   ██║██████╔╝███████║     ██║
  ╚██╔╝  ██║   ██║╚██╗ ██╔╝██╔══██╗██╔══██║██   ██║
   ██║   ╚██████╔╝ ╚████╔╝ ██║  ██║██║  ██║╚█████╔╝
   ╚═╝    ╚═════╝   ╚═══╝  ╚═╝  ╚═╝╚═╝  ╚═╝ ╚════╝
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a,b,c,m;
        cin>>a>>b>>c>>m;
        int mx=a+b+c-3;
        int mn=0;
        mn=max(0LL,a-1-b-c);
        mn=max(mn,b-1-a-c);
        mn=max(mn,c-1-a-b);
        if(mn<=m&&m<=mx){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;   
        }
    }
    return 0;
}