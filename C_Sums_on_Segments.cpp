#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> f(vector<int>&arr,int l,int r){
    int mx=0,mn=0,mx_sum=0,mn_sum=0;
    for(int i=l;i<=r;i++){
        mn_sum=min(arr[i],mn_sum+arr[i]);
        mn=min(mn,mn_sum);
        mx_sum=max(arr[i],mx_sum+arr[i]);
        mx=max(mx,mx_sum);
    }
    return {mn,mx};
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(auto &it:arr)cin>>it;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(arr[i]!=-1&&arr[i]!=1){
                idx=i;
                break;
            }
        }
        set<int>ans;
        if(idx==-1){
            auto [mn,mx]=f(arr,0,n-1);
            for(int i=mn;i<=mx;i++){
                ans.insert(i);
            }
        }else{
            auto [mn1,mx1]=f(arr,0,idx-1);
            auto [mn2,mx2]=f(arr,idx+1,n-1);
            for(int i=mn1;i<=mx1;i++){
                ans.insert(i);
            }
            for(int i=mn2;i<=mx2;i++){
                ans.insert(i);
            }
            int mn_l=0,mx_l=0,sum=0;
            for(int i=idx-1;i>=0;i--){
                sum+=arr[i];
                mn_l=min(sum,mn_l);
                mx_l=max(sum,mx_l);
            }
            sum=0;
            int mn_r=0,mx_r=0;
            for(int i=idx+1;i<n;i++){
                sum+=arr[i];
                mn_r=min(sum,mn_r);
                mx_r=max(sum,mx_r);
            }
            for(int i=mn_l+mn_r+arr[idx];i<=mx_l+arr[idx]+mx_r;i++){
                ans.insert(i);
            }
        }
        for(auto it:arr){
            ans.insert(it);
        }
        cout<<ans.size()<<endl;
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}