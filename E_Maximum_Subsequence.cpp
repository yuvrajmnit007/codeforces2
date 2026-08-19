#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>vec1,vec2;
    int a=n/2,b=n-a;
    for(int i=0;i<(1<<a);i++){
        int sum=0;
        for(int j=0;j<a;j++){
            if(i&(1<<j)){
                sum+=arr[j];
            }
        }
        vec1.push_back(sum%k);
    }
    for(int i=0;i<(1<<b);i++){
        int sum=0;
        for(int j=0;j<b;j++){
            if(i&(1<<j)){   
                sum+=arr[j+a];
            }
        }
        vec2.push_back(sum%k);
    }
    sort(vec2.begin(),vec2.end());
    int ans=0;
    for(int i=0;i<vec1.size();i++){
        int x=(k-vec1[i]);
        auto it=lower_bound(vec2.begin(),vec2.end(),x);
        if(*it>=x&&it!=vec2.begin()){
            it--;
        }
        ans=max(ans,(vec1[i]+*it)%k);
        ans=max(ans,(vec2.back()+vec1[i])%k);
    }
    cout<<ans<<endl;
    return 0;
}