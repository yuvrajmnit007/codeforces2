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
        vector<int>arr(3);
        for(int i=0;i<3;i++){
            cin>>arr[i];
        }
        int a=arr[0],b=arr[1],c=arr[2];
        sort(arr.begin(),arr.end());
        if(a==b||a==c||b==c){
            cout<<0<<endl;
        }else{
            int cnt=arr[2]-arr[1];
            int cnt1=arr[1]-arr[0];
            cout<<min(cnt,cnt1)<<endl;
        }
    }
    return 0;
}