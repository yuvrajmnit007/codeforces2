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
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==0)zero++;
        }
        if(zero<=1){
            cout<<-1<<endl;
        }else{
            if(arr[0]==0&&arr[n-1]==0){
                cout<<0<<endl;
            }else if(arr[0]==0||arr[n-1]==0){
                cout<<1<<endl;
            }else{
                cout<<2<<endl;
            }
        }
    }
    return 0;
}