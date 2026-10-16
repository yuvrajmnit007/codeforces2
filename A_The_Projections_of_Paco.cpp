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
        int pos=0;
        vector<int>arr(n);
        vector<int>pre;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            pos=(arr[i]-pos+arr[i]);
            pre.push_back(pos);
        }
        // // cout<<pos<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<pre[i]<<" ";
        // }
        if(n%2==0){
            cout<<-pre[n-1]/2<<endl;
        }else{
            cout<<pre[n-1]/2<<endl;
        }
        // cout<<endl;
    }
    return 0;
}