#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n);
    int hcf=0,mx=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mx=max(mx,arr[i]);
        hcf=__gcd(hcf,arr[i]);
    }
    mx/=hcf;
    for(int i=0;i<n;i++){
        arr[i]/=hcf;
    }
    vector<int>vec(mx+1,0),primes;
    for(int i=2;i<=mx;i++){
        if(vec[i]==0){
            primes.push_back(i);
        }if(vec[i]==1)continue;
        int j;
        for(j=2*i;j<=mx;j+=i){
            vec[j]=1;
        }
    }
    int ans=0;
    for(int i=0;i<primes.size();i++){
        int cnt=0;
        int p=primes[i];
        for(int j=0;j<n;j++){
            if(arr[i]%p==0){
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    //cout<<ans<<endl;
    if(ans==0)ans=n+1;
    cout<<n-ans<<endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     int hcf=0,mx=0;
//     for(int&i:arr){
//         cin>>i;
//         hcf=__gcd(hcf,i);
//         mx=max(mx,i);
//     }
//     for(int&i:arr)i/=hcf;
//     mx/=hcf;
//     vector<int>spf(mx+1);
//     for(int i=2;i<=mx;i++){
//         if(!spf[i]){
//             spf[i]=i;
//             if(i*i<=mx){
//                 for(int j=i*i;j<=mx;j+=i){
//                     if(!spf[j])spf[j]=i;
//                 }
//             }
//         }
//     }
//     unordered_map<int,int>mp;
//     int ans=0;
//     for(int x:arr){
//         while(x>1){
//             int p=spf[x];
//             mp[p]++;
//             ans=max(ans,mp[p]);
//             while(x%p==0)x/=p;
//         }
//     }
//     if(ans==0)ans=n+1;
//     cout<<n-ans<<endl;
//     return 0;
// }