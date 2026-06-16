#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            vec.push_back({a,b});
        }
        sort(vec.begin(),vec.end());
        vector<int>arr(n,0),arr1(n);
        arr[0]=vec[0].second;
        arr1[0]=vec[0].first;
        for(int i=1;i<n;i++){
            arr[i]=arr[i-1]+vec[i].second;
            arr1[i]=vec[i].first;
        }
        int ans=-1e18;
        for(int i=0;i<n;i++){
            int idx=lower_bound(arr1.begin(),arr1.end(),arr1[i]+k)-arr1.begin()-1;
            if(idx<i)continue;
            if(i>0)ans=max(ans,arr[idx]-arr[i-1]);
            else ans=max(ans,arr[idx]);
        }
        cout<<ans<<endl;
    }
    return 0;
}