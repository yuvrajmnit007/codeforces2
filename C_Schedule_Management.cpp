#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<int>arr(m);
        map<int,int>mp;
        for(int i=0;i<m;i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        vector<int>vec;
        for(auto it:mp){
            vec.push_back(it.second);
        }
        sort(vec.rbegin(),vec.rend());
        int l=0,h=1e12;
        int ans;
        while(l<=h){
            int mid=(l+h)/2;
            vector<int>hour(n,mid);
            for(int i=0;i<min(n,(int)vec.size());i++){
                hour[i]-=vec[i];
            }
            int sum=0;
            for(int i=n;i<vec.size();i++){
                sum+=vec[i];
            }
            int sum1=0;
            for(int i=0;i<n;i++){
                if(hour[i]<0){
                    sum1+=2*hour[i];
                }else{
                    if(hour[i]%2==1){
                        hour[i]--;
                    }
                    sum1+=hour[i];
                }
            }
            if(sum1>=2*sum){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}