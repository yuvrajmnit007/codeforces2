#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int>arr(k);
        for(int i=0;i<k;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int one=0,sum=0;
        for(int i=0;i<k-1;i++){
            if(arr[i]==1)one++;
            else{
                sum+=(arr[i]-1);
            }
        }
        cout<<sum*2+(k-1)<<endl;

    }
    return 0;
}