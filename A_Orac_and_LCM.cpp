// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// int power(int base,int expo){
//     int ans=1;
//     while(expo){
//         if(expo%2==1){
//             ans*=base;
//         }
//         base*=base;
//         expo/=2;
//     }
//     return ans;
// }
// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t=1;
//     while (t--) {
//         int n;
//         cin>>n;
//         vector<int>arr(n);
//         int mx=0;
//         for(int i=0;i<n;i++){
//             cin>>arr[i];
//             mx=max(mx,arr[i]);
//         }
//         vector<int>primes;
//         vector<int>vec(mx+1,0);
//         for(int i=2;i<=mx;i++){
//             if(vec[i]==0){
//                 primes.push_back(i);
//                 for(int j=i;j<=mx;j+=i){
//                     vec[j]=1;
//                 }
//             }
//         }
//         vector<pair<pair<int,int>,int>>temp;
//         int ans=1;
//         for(auto it:primes){
//             if(it>mx)break;
//             int prev1=1e18,prev2=1e18;
//             for(auto a:arr){
//                 int freq=0;
//                 while(a%it==0){
//                     freq++;
//                     a/=it;
//                 }
//                 if(prev1>=freq){
//                     prev2=prev1;
//                     prev1=freq;
//                 }else if(freq<prev2){
//                     prev2=freq;
//                 }
//             }
//             temp.push_back({{it,prev1},prev2});
//         }
//         for(auto it:temp){
//             int p=it.first.first;
//             int prev1=it.first.second;
//             int prev2=it.second;
//             if(prev2>0){
//                 ans*=power(p,prev2);
//             }
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }
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
        vector<int>suf(n,0);
        suf[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=__gcd(suf[i+1],arr[i]);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            int val=__gcd(arr[i],suf[i+1]);
            int temp=(arr[i]*suf[i+1])/val;
            ans=__gcd(ans,temp);
        }
        cout<<ans<<endl;
    }
    return 0;
}