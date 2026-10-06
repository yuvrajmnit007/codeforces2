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
        if(n==2){
            cout<<-1<<endl;
            continue;
        }
        vector<int>ans;
        ans.push_back(2);
        ans.push_back(4);
        ans.push_back(6);
        int a=6;
        for(int i=4;i<=n;i++){
            ans.push_back(2*a);
            a*=2;
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}