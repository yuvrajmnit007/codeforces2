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
                vec.push_back({n/i,i});
            }
        }
        sort(vec.begin(),vec.end());
        int m=vec.size();
        vector<int>pref(m,0);
        pref[0]=vec[0].first*vec[0].second;
        for(int i=1;i<m;i++){
            pref[i]=pref[i-1]+(vec[i].first-vec[i-1].first)*(vec[i].second);
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            int l=0,r=m;
            while(r-l>1){
                int mid=(l+r)/2;
                if(vec[mid].second>=y)l=mid;
                else r=mid;
            }
            int idx1=l;
            l=0,r=m;
            while(r-l>1){
                int mid=(l+r)/2;
                if(vec[mid].first<=x)l=mid;
                else r=mid;
            }
            int idx2=l;
            idx1=min(idx1,idx2);
            int ans=y*vec[idx1].first+pref[idx2]-pref[idx1];
            if(idx2+1<m){
                ans+=(x-vec[idx2].first)*min(y,vec[idx2+1].second);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}