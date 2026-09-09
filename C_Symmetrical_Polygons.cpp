#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        map<int,int>mp;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        vector<int>vec;
        int sum=0;
        for(auto it:mp){
            if(it.second%2==1){
                vec.push_back(it.first);
            }
            int fre=it.second/2;
            sum+=(fre*2*it.first);
        }
        int p=n-vec.size();
        sort(vec.begin(),vec.end());
        int ans=0;
        if(p>=4){
            ans=sum;
        }
        if(vec.size()>=1){
            for(int i=0;i<vec.size();i++){
                if(sum>vec[i])ans=max(ans,sum+vec[i]);
            }
        }
        if(vec.size()>=2){
            for(int i=1;i<vec.size();i++){
                if(sum+vec[i-1]>vec[i])ans=max(ans,sum+vec[i-1]+vec[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}