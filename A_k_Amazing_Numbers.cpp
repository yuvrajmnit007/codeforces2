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
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]].push_back(i);
        }
        vector<int>ans(n+1,1e18);
        for(auto x:mp){
            int v=x.first;
            auto vec=x.second;
            vec.push_back(n);
            int prev=-1;
            int mn=0;
            for(int i=0;i<vec.size();i++){
                mn=max(mn,vec[i]-prev);
                prev=vec[i];
            }
            ans[mn-1]=min(ans[mn-1],v);
        }
        for(int i=1;i<n;i++){
            ans[i]=min(ans[i],ans[i-1]);
        }
        for(int i=0;i<n;i++){
            if(ans[i]==1e18){
                cout<<-1<<" ";
            }
            else{
                cout<<ans[i]<<" ";
            }
        }
        cout<<endl;

    }
    return 0;
}