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
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>inc(n),dec(n);
    for(int i=0;i<n;i++){
        inc[i]=i;
        dec[i]=i;
    }
    for(int i=1;i<n;i++){
        if(a[i]<=a[i-1]){
            inc[i]=inc[i-1];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(a[i]<=a[i+1]){
            dec[i]=dec[i+1];
        }
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        if(inc[r-1]<=dec[l-1]){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}