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
        int a,m;
        cin>>a>>m;
        int val=__gcd(a,m);
        a/=val;
        m/=val;
        int ans=1;
        for(int i=2;i*i<=m;i++){
            int cnt=0;
            while(m%i==0){
                cnt++;
                m/=i;
            }
            if(cnt==0)continue;
            ans=ans*(pow(i,cnt)-pow(i,cnt-1));
        }
        if(m>1)ans=ans*(m-1);
        cout<<ans<<endl;
    }
    return 0;
}