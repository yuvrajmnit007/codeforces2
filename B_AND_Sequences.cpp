#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int fact(int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=(ans*i)%mod;
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>temp;
        temp=arr;
        for(int i=1;i<n;i++){
            arr[i]=arr[i-1]&arr[i];
        }
        int val=arr[n-1];
        int ans=0;
        for(int i=0;i<n;i++){
            if(temp[i]==val){
                ans++;
            }
        }
        cout<<((ans*(ans-1))%mod*(fact(n-2)))%mod<<endl;
    }
    return 0;
}