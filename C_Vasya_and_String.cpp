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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans=0;
    int i=0,j=0;
    int cntb=0;
    while(true){
        while(j<n&&cntb<=k){
            if(s[j]=='b'){
                cntb++;
            }
            j++;
        }
        if(cntb>k){
            ans=max(ans,j-i-1);
            while(i<n&&cntb>k){
                if(s[i]=='b'){
                    cntb--;
                }
                i++;
            }
            continue;
        }
        ans=max(ans,j-i);
        if(j==n)break;
    }
    int cnta=0;
    i=0;
    j=0;
    while(true){
        while(j<n&&cnta<=k){
            if(s[j]=='a'){
                cnta++;
            }
            j++;
        }
        if(cnta>k){
            ans=max(ans,j-i-1);
            while(i<n&&cnta>k){
                if(s[i]=='a'){
                    cnta--;
                }
                i++;
            }
            continue;
        }
        ans=max(ans,j-i);
        if(j==n)break;
    }
    cout<<ans<<endl;
    return 0;
}