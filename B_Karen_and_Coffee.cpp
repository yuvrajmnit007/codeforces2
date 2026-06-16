#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while (t--) {
        int n,k,m;
        cin>>n>>k>>m;
        vector<pair<int,int>>vec;
        int mn=1e18,mx=-1e18;
        for(int i=0;i<n;i++){
            int l,r;
            cin>>l>>r;
            mn=min(l,mn);
            mx=max(r,mx);
            vec.push_back({l,r});
        }
        vector<int>arr(mx-mn+2,0);
        for(auto it:vec){
            int l=it.first-mn;
            int r=it.second-mn;
            arr[l]++;
            if(r+1<arr.size())arr[r+1]--;
        }
        for(int i=1;i<mx-mn+2;i++){
            arr[i]+=arr[i-1];
        }
        for(int i=0;i<mx-mn+1;i++){
            if(arr[i]>=k){
                arr[i]=1;
            }else{
                arr[i]=0;
            }
        }
        for(int i=1;i<mx-mn+2;i++){
            arr[i]+=arr[i-1];
        }
        while(m--){
            int l,r;
            cin>>l>>r;
            l=max(l,mn);
            r=min(r,mx);
            if(l>r){
                cout<<0<<endl;
                continue;
            }
            l=l-mn-1;
            r=r-mn;
            if(l>=0){
                cout<<arr[r]-arr[l]<<endl;
            }else{
                cout<<arr[r]<<endl;
            }
        }
    }
    return 0;
}