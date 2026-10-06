#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<n;i++){
            arr[i]=min(arr[i],arr[i-1]);
        }
        // for(auto it:arr){
        //     cout<<it<<" ";
        // }
        // cout<<"\n";
        vector<vector<int>>vec(n,vector<int>(k,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                cin>>vec[i][j];
            }
        }
        int ans=1e9;
        priority_queue<int,vector<int>,greater<int>>pq;
        int sum=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<k;j++){
                pq.push(vec[i][j]);
                sum+=vec[i][j];
            }
            while(pq.size()>0&&sum>=arr[i]){
                ans=min(ans,(int)pq.size());
                sum-=pq.top();
                pq.pop();
            }
        }
        cout<<min(ans,k)<<"\n";
    }
    return 0;
}