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
        vector<pair<int,int>>ans(n);
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            vector<int>arr(k);
            int mx=0;
            for(int j=0;j<k;j++){
                cin>>arr[j];
                arr[j]-=j;
                arr[j]++;
            }
            sort(arr.begin(),arr.end());
            ans[i]={arr[k-1],k};
        }
        sort(ans.begin(),ans.end());
        int sum=ans[0].second;
        int val=ans[0].first;
        for(int i=1;i<n;i++){
            val=max(val,ans[i].first-sum);
            sum+=ans[i].second;
        }
        cout<<val<<endl;
    }
    return 0;
}