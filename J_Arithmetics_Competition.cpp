#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,q;
        cin>>n>>m>>q;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>arr1(m);
        for(int i=0;i<m;i++){
            cin>>arr1[i];
        }
        sort(arr.rbegin(),arr.rend());
        sort(arr1.rbegin(),arr1.rend());
        vector<int>pre1(n+1,0);
        vector<int>pre2(m+1,0);
        for(int i=1;i<=n;i++){
            pre1[i]=pre1[i-1]+arr[i-1];
        }
        for(int i=1;i<=m;i++){
            pre2[i]=pre2[i-1]+arr1[i-1];
        }
        while(q--){
            int x,y,z;
            cin>>x>>y>>z;
            int low=max(0LL,z-y);
            int high=min(x,z);
            int ans=-1;
            while(high-low>2){
                int m1=low+(high-low)/3;
                int m2=high-(high-low)/3;
                int sum1=pre1[m1]+pre2[z-m1];
                int sum2=pre1[m2]+pre2[z-m2];
                if(sum1<sum2){
                    low=m1;
                }else{
                    high=m2;
                }
            }
            for(int i=low;i<=high;i++){
                if(i>=0&&i<=x&&(z-i)>=0&&(z-i)<=y){
                    ans=max(ans,pre1[i]+pre2[z-i]);
                }
            }
            cout<<ans<<endl;
        }
    }
return 0;
}