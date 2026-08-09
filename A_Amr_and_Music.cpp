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
    vector<pair<int,int>>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=i+1;
    }
    sort(arr.begin(),arr.end());
    vector<int>ans;
    int sum=0,i=0;
    while(i<n&&sum+arr[i].first<=k){
        sum+=arr[i].first;
        ans.push_back(arr[i].second);
        i++;
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}