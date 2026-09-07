#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f(vector<int>&ans,vector<int>&arr){
    int n=arr.size();
    vector<int>dis(n,1e18);
    int prev=-1e18;
    for(int i=0;i<n;i++){
        if(ans[i]==1)prev=i;
        if(prev!=-1e18)dis[i]=min(dis[i],i-prev);
    }
    int prev1=1e18;
    for(int i=n-1;i>=0;i--){
        if(ans[i]==1)prev1=i;
        if(prev1!=1e18)dis[i]=min(dis[i],prev1-i);
    }
    for(int i=0;i<n;i++){
        if(arr[i]!=-1&&dis[i]!=arr[i]){
            return 0;
        }
    }
    return 1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        bool ok=1;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            
        }
        vector<int>vec(n+1,0);
        for(int i=0;i<n;i++){
            int l=max(0LL,i-arr[i]+1);
            int r=min(n-1,i+arr[i]-1);
            if(l<=r){
                vec[l]++;
                vec[r+1]--;
            }
        }
        vector<int>ans(n,0);
        int sum=0,temp=0;
        for(int i=0;i<n;i++){
            sum+=vec[i];
            if(sum==0){
                ans[i]=1;
                temp++;
            }
        }
        if(temp==0){
            cout<<-1<<endl;
            continue;
        }else{
            if(!f(ans,arr)){
                cout<<-1<<endl;
            }else{
                for(auto it:ans){
                    cout<<it;
                }
                cout<<endl;
            }
        }
    }
    return 0;
}