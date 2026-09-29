#include <bits/stdc++.h>
using namespace std;
#define int long long
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
        vector<int>vec(32,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                if(arr[i]&(1<<j)){
                    vec[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<32;j++){
                if(arr[i]&(1<<j)){
                    temp+=(n-vec[j])*pow(2,j);
                }else{
                    temp+=vec[j]*pow(2,j);
                }
            }
            ans=max(ans,temp);
        }
        cout<<ans<<endl;
    }
    return 0;
}