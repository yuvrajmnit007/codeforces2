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
        set<int>st;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            mp[x]++;
            st.insert(x);
        }
        vector<int>vec(n+1,0);
        for(auto it:st){
            for(int i=it;i<=n;i+=it){
                vec[i]+=mp[it];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,vec[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}