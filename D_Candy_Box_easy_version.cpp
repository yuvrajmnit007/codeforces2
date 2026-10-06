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
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        vector<int>vec;
        for(auto it:mp){
            vec.push_back(it.second);
        }
        int r=vec.size();
        sort(vec.begin(),vec.end());
        vector<int>arr1(n+1,0);
        // for(auto it:vec){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        int ans=vec[r-1];
        arr1[vec[r-1]]=1;
        for(int i=r-2;i>=0;i--){
            while(vec[i]>0&&arr1[vec[i]]==1){
                vec[i]--;
            }
            arr1[vec[i]]=1;
            ans+=vec[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}