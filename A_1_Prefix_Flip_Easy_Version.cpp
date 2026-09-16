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
        string a,b;
        cin>>a>>b;
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            if(a[i]!=b[i]){
                ans.push_back(i+1);
                ans.push_back(1);
                ans.push_back(i+1);
            }
        }
        cout<<ans.size()<<" ";
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
