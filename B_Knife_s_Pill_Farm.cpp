#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        multiset<int>st;
        int ans=-1e18;
        int mx=-1e18;
        int sum=0;
        for(int i=0;i<n;i++){
            if(st.size()==m-1){
                ans=max(ans,m*arr[i]-sum);
            }
            st.insert(arr[i]);
            sum+=arr[i];
            if(st.size()>m-1){
                auto it=st.end();
                it--;
                sum-=(*it);
                st.erase(it);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}