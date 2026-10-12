#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int m=n-4;
        vector<int>val(m);
        for(int i=0;i<m;i++){
            val[i]=a[i]+a[i+2]-a[i+4];
        }
        map<int,int>freq;
        int ans=0;
        for(int i=0;i<m;i++){
            ans+=freq[val[i]];
            freq[val[i]]++;
        }
        for(int i=0;i<m;i++){
            if(i>=2&&val[i]==val[i-2]){
                ans--;
            }
            if(i>=4&&val[i]==val[i-4]){
                ans--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}