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
        map<int,int>mp;
        for(auto &it:arr){
            cin>>it;
            mp[it]++;
        }
        sort(arr.begin(),arr.end());
        bool ok=0;
        for(int i=0;i<n;i++){
            if(mp[i]<2*k-1)break;
            if(mp[i]==2*k-1){
                ok=1;
            }
        }
        if(ok){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}