#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a,b,k;
        cin>>a>>b>>k;
        vector<int>arr(k),arr1(k);
        map<int,int>boy,girl;
        for(int i=0;i<k;i++){
            cin>>arr[i];
            boy[arr[i]]++;
        }
        for(int i=0;i<k;i++){
            cin>>arr1[i];
            girl[arr1[i]]++;
        }
        int ans=0;
        for(int i=0;i<k;i++){
            ans+=(k-boy[arr[i]]-girl[arr1[i]]+1);
        }
        cout<<ans/2<<endl;
    }
    return 0;
}