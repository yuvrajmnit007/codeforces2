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
    vector<int>arr(n);
    vector<int>pre(n+1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        pre[i+1]=pre[i]+arr[i];
    }
    int ans=k*pre[n];
    sort(pre.begin()+1,pre.end()-1);
    for(int i=1;i<=k-1;i++){
        ans-=pre[i];
    }
    cout<<ans<<endl;
    return 0;
}

// . arr={2 ,3 ,4 ,5}
//. s4->sum from1 to 4;
//s3->sum from1 to 3;





