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
    int n,x;
    cin>>n>>x;
    vector<int>arr(2*n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i+n]=arr[i];
    }
    int ans=0;
    int days=0;
    int total=0;
    int l=0;
    for(int i=0;i<2*n;i++){
        total+=(arr[i])*(arr[i]+1)/2;
        days+=arr[i];
        while(l<=i&&days-arr[l]>=x){
            total-=(arr[l])*(arr[l]+1)/2;
            days-=arr[l];
            l++;
        }
        if(days>=x){
            int r=arr[l]-(x-(days-arr[l]));
            int val=(r*(r+1))/2;
            ans=max(ans,total-val);
            days-=arr[l];
            total-=(arr[l])*(arr[l]+1)/2;
            l++;
        }
    }
    cout<<ans<<endl;
    return 0;
}