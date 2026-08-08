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
    int t=1;
    while (t--) {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int temp=n+1;
        int ans=n-1;
        cout<<1<<" "<<arr[0]<<endl;
        if(arr[1]*arr[2]>0){
            cout<<2<<" "<<arr[1]<<" "<<arr[2]<<endl;
            ans-=2;
        }else{
            int i=1;
            while(i<n&&arr[i]<=0){
                i++;
            }
            cout<<1<<" "<<arr[i]<<endl;
            temp=i;
            ans-=1;
        }
        cout<<ans<<" ";
        if(temp==n+1){
            for(int i=3;i<n;i++){
                cout<<arr[i]<<" ";
            }
        }else{
            for(int i=1;i<n;i++){
                if(i!=temp){
                    cout<<arr[i]<<" ";
                }
            }
        }
    }
    return 0;
}