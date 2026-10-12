#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin>>n>>d;
        vector<int>ans;
        ans.push_back(1);
        if(n>=3||d%3==0){
            ans.push_back(3);
        }
        if(((n>=6)||(n>=3&&d%3==0)||d==9))ans.push_back(9);
        if(d==5)ans.push_back(5);
        if(d==7||(n>=3))ans.push_back(7);
        sort(ans.begin(),ans.end());
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}