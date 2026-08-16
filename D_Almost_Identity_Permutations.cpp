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
    int ans=1,temp=1;
    for(int i=2;i<=k;i++){
        if(i==2){
            temp=n*(n-1)/2;
            ans+=temp;
        }else if(i==3){
            temp=temp*(n-2)/3;
            ans+=2*temp;
        }else{
            temp=temp*(n-3)/4;
            ans+=9*temp;
        }
    }
    cout<<ans<<endl;
    return 0;
}