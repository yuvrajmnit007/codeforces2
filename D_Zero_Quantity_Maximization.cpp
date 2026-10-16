#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    map<pair<int,int>,int>mp;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            int gcd=__gcd(a[i],b[i]);
            int x=a[i]/gcd;
            int y=b[i]/gcd;
            mp[{x,y}]++;
        }
    }
    int ans=0;
    for(auto it:mp){
        ans=max(ans,it.second);
    }
    for(int i=0;i<n;i++){
        if(a[i]==0 && b[i]==0){
           ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}