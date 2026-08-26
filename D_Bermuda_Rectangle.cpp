#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,q;
        cin>>n>>q;
        vector<pair<int,int>>vec;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                vec.push_back({i,n/i});
            }
        }
        sort(vec.begin(),vec.end());
        int m=vec.size();
        vector<int>pref(m+1,0);
        pref[0]=vec[0].first*vec[0].second;
        for(int i=1;i<m;i++){
            pref[i]=pref[i-1]+(vec[i].first-vec[i-1].first)*(vec[i].second);
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            
        }
    }
    return 0;
}