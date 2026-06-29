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
        map<int,int>mp;
        vector<vector<int>>vec;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            vector<int>arr(k);
            for(int j=0;j<k;j++){
                cin>>arr[j];
                mp[arr[j]]++;
            }
            vec.push_back(arr);
        }
        bool ans=false;
        for(int i=0;i<n;i++){
            bool temp=true;
            for(auto it:vec[i]){
                if(mp[it]==1){
                    temp=0;
                    break;
                }
            }
            if(temp){
                ans=1;
                break;
            }
        }
        if(ans){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}