#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=998244353;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin>>n>>d;
        vector<int>arr(n);
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>vec=arr;
        for(int i=0;i<n;i++){
            vec.push_back(arr[i]);
        }
        vector<int>pref(2*n+1,0);
        for(int i=1;i<=2*n;i++){
            pref[i]=pref[i-1]+vec[i-1];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int sum1=pref[i+n]-pref[i+n-d];
            int sum2=pref[i+d+1]-pref[i+1];
            if(2*arr[i]*d-sum1-sum2>0){
                ans+=2*arr[i]*d-sum1-sum2;
                ans%=MOD;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}