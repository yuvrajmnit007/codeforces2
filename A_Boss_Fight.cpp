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
        map<int,int>mp;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
            mp[arr[i]]++;
        }
        for(auto it:mp){
            if(it.second>(n+1)/2){
                int temp=n-it.second;
                sum-=(it.second-temp-2)*it.first;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}