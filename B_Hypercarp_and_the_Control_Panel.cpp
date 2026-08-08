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
//#define int long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>arr(n+2);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        arr[0]=arr[n+1]=0;
        int ans=n;
        int mx=0;
        for(int i=2;i<=n;i++){
            mx=max(mx,((arr[i-1]==arr[i-2])+(arr[i]==arr[i+1])-(arr[i]==arr[i-2])-(arr[i-1]==arr[i+1])));
            if(arr[i]==arr[i-1]){
                ans--;
            }
        }
        cout<<ans+mx<<endl;
    }
    return 0;
}