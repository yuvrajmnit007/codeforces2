#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>>vec;
        vector<int>arr(n+3,0);
        int p=k;
        while(p--){
            int l,r;
            cin>>l>>r;
            arr[l]++;
            arr[r+1]--;
            vec.push_back({l,r});
        }
        for(int i=1;i<=n;i++){
            arr[i]+=arr[i-1];
        }
        int total=0;
        vector<int>one(n+1,0);
        vector<int>two(n+1,0);
        for(int i=1;i<=n;i++){
            if(arr[i]>0)total++;
            one[i]=one[i-1]+(arr[i]==1);
            two[i]=two[i-1]+(arr[i]==2);
        }
        int ans=-1e18;
        for(int i=0;i<k;i++){
            int l1=vec[i].first;
            int r1=vec[i].second;
            int loss1=one[r1]-one[l1-1];
            for(int j=i+1;j<k;j++){
                int l2=vec[j].first;
                int r2=vec[j].second;
                int loss2=one[r2]-one[l2-1];
                int l3=max(l1,l2);
                int r3=min(r1,r2);
                int common1=0;
                int common2=0;
                if(l3<=r3){
                    common1=one[r3]-one[l3-1];
                    common2=two[r3]-two[l3-1];
                }
                ans=max(ans,total-loss1-loss2+common1-common2);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}