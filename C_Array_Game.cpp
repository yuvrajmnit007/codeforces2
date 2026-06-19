#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(k>=3){
            cout<<0<<endl;
            continue;
        }
        vector<int>p;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                p.push_back(abs(arr[i]-arr[j]));
            }
        }
        sort(p.begin(),p.end());
        int ans=1e18+9;
        ans=min(ans,p[0]);
        for(int i=0;i<n;i++){
            ans=min(ans,arr[i]);
        }
        if(k==2){
            for(int i=0;i<n;i++){
                int it=lower_bound(p.begin(),p.end(),arr[i])-p.begin();
                if(it<p.size()){
                    ans=min(ans,abs(p[it]-arr[i]));
                }
                if(it!=0){
                    ans=min(ans,abs(p[it-1]-arr[i]));
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}