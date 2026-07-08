#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i]<m){
            cnt1++;
        }else if(arr[i]==m){
            cnt2++;
        }
    }
    cout<<m-cnt1+cnt2<<endl;
    return 0;
}