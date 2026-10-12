#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w;
    cin>>n>>w;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i>0)arr[i]+=arr[i-1];
    }
    sort(arr.begin(),arr.end());
    cout<<max(0LL,-max(0LL,-arr[0])+min(w,w-arr[n-1])+1)<<endl;
    return 0;
}