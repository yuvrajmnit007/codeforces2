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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        s+=s;
        int a=0,b=0;
        for(int i=0;i<2*n;i++){
            if(s[i]=='1'){
                int temp=(i+1)%(2*n);
                if(s[temp]=='0'){
                    if(i%2){
                        b++;
                    }else{
                        a++;
                    }
                }else{
                    if(i%2){
                        a++;
                    }else{
                        b++;
                    }
                }
            }
        }
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}