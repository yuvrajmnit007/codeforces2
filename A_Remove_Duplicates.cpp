#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    map<int,int>mp;
    vector<int>ans;
    for(int i=n-1;i>=0;i--){
        if(mp[vec[i]]==0){
            ans.push_back(vec[i]);
        }
        mp[vec[i]]++;
    }
    cout<<ans.size()<<endl;
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}