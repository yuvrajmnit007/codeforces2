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
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            int l,r;
            cin>>l>>r;
            vec.push_back({l,r});
        }
        int low=0,hi=1e9;
        int ans;
        while(low<=hi){
            int mid=(low+hi)/2;
            bool ok=true;
            int l=0,r=0;
            for(int i=0;i<n;i++){
                int p=vec[i].first;
                int q=vec[i].second;
                l-=mid;
                r+=mid;
                int a,b;
                l=max(p,l);
                r=min(q,r);
                if(l>r){
                    ok=false;
                }
            }
            if(ok){
                ans=mid;
                hi=mid-1;
            }else{
                low=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}