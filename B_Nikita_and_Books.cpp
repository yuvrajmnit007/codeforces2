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
        int sum=0;
        bool ans=true;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
            if(sum*2<(i+1)*(i+2)){
                ans=0;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}