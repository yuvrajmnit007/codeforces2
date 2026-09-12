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
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int idx1=-1,idx2=-1,cnt=0;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                idx1=i-1;
                break;
            }
        }
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                cnt++;
                idx2=i+1;
            }
        }
        if(cnt==0){
            cout<<0<<endl;
        }else{
            if(idx2==idx1+1){
                cout<<0<<endl;
            }else{
                cout<<max(1LL,idx2-idx1-2)<<endl;
            }
        }
    }
    return 0;
}