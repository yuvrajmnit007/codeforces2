#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>>arr(n);
    int sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum+=x;
        arr[i]={x,i};
    }
    vector<int>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int rem=sum-arr[i].first;
        if(i!=n-1){
            if(rem-arr[n-1].first==arr[n-1].first){
                ans.push_back(arr[i].second+1);
            }
        }else{
            if(rem-arr[n-2].first==arr[n-2].first){
                ans.push_back(arr[i].second+1);
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}