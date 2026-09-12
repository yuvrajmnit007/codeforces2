#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>f(vector<int>&arr){
    map<int,int>freq;
    int n=arr.size();
    map<int,int>mp;
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
        mp[arr[i]]=max(mp[arr[i]],i);
    }
    vector<pair<int,int>>vec;
    for(auto it:mp){
        vec.push_back({it.second,it.first});
    }
    sort(vec.begin(),vec.end());
    vector<int>ans;
    for(auto it:vec){
        int val=it.second;
        for(int i=0;i<freq[val];i++){
            ans.push_back(val);
        }
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>arr(n);
        vector<int>brr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            cin>>brr[i];
        }
        if(f(arr)==f(brr)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}