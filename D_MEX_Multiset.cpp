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
        int zero=0;
        vector<char>ans(n);
        bool ok=false;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==0){
                zero++;
                if(ok){
                    ans[i]='A';
                }else{
                    ans[i]='B';
                    ok=true;
                }
            }
            else ans[i]='C';
        }
        if(zero==1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                cout<<ans[i];
            }
            cout<<endl;
        }
    }
    return 0;
}