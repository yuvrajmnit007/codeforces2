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
        if(n-k<2){
            cout<<-1<<endl;
            continue;
        }
        int add0=k/2;
        int add1=k-add0;
        string s="";
        for(int i=0;i<n-k;i++){
            int len=1;
            if(i%2==0&&add0>0) {
                len+=add0;
                add0=0;
            }else if(i%2==1&&add1>0){
                len+=add1;
                add1=0;
            }
            if(i%2==0)s.append(len,'0');
            else s.append(len,'1');
        }
        cout<<s<<endl;
    }
    return 0;
}