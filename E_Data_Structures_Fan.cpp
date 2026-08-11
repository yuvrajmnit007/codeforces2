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
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<int>pre(n+1,0);
        int one=0,zero=0;
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]^arr[i];
            if(s[i]=='1')one^=arr[i];
            else zero^=arr[i];
        }
        while(q--){
            int a;
            cin>>a;
            if(a==1){
                int l,r;
                cin>>l>>r;
                int val=pre[r]^pre[l-1];
                zero^=val;
                one^=val;
            }else{
                int g;
                cin>>g;
                if(g==0){
                    cout<<zero<<" ";
                }else{
                    cout<<one<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}