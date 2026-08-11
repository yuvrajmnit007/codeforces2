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
    int a,b,c;
    cin>>a>>b>>c;
    int mn=min({a,b,c});
    int ans=(a/3+b/3+c/3);
    int val=((a-1)/3+(b-1)/3+(c-1)/3);
    int val1=((a-2)/3+(b-2)/3+(c-2)/3);
    if(mn>=1){
        ans=max(ans,val+1);
    }
    if(mn>=2){
        ans=max(ans,val1+2);
    }
    cout<<ans<<endl;
    return 0;
}