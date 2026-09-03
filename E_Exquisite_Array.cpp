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
        vector<pair<int,int>>vec;
        for(int i=0;i<n-1;i++){
            vec.push_back({abs(arr[i+1]-arr[i]),i});
        }
        sort(vec.begin(),vec.end());
        vector<int>ans(n-1,0);
        set<int>st;
        st.insert(0);
        st.insert(n-1);
        for(auto [diff,idx]:vec){
            auto it1=st.upper_bound(idx);
            it1--;
            auto it2=st.lower_bound(idx+1);
            int l=*it1;
            int r=*it2;
            ans[diff-1]+=(idx-l+1)*(r-idx);
            st.insert(idx);
            st.insert(idx+1);
        }
        for(int i=n-3;i>=0;i--){
            ans[i]+=ans[i+1];
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}