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
        vector<int>arr(n),arr1(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            arr1[i]=arr[i]/4;
        }
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr1[i]].push_back(i);
        }
        vector<int>ans(n);
        for(auto it:mp){
            vector<int>vec;
            for(auto k:it.second){
                vec.push_back(arr[k]);
            }
            sort(vec.begin(),vec.end());
            int p=0;
            for(auto k:it.second){
                ans[k]=vec[p];
                p++;
            }
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}