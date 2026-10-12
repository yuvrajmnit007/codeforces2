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
        vector<int>a(n),b(n);
        a[0]=1;
        for(int i=1;i<n;i++){
            cin>>a[i];
        }
        for(auto &it:b){
            cin>>it;
        }
        sort(a.begin(),a.end());
        multiset<int>st;
        for(auto it:b){
            st.insert(it);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            auto it=st.upper_bound(a[i]);
            if(it==st.end()){
                continue;
            }
            st.erase(it);
        }
        cout<<st.size()<<endl;
    }
    return 0;
}