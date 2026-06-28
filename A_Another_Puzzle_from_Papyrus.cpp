#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,c;
        cin>>n>>c;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int ans1=0;
        for(int i=0;i<n;i++){
            if(a[i]>=b[i])ans1+=(a[i]-b[i]);
            else{
                ans1=1e18;
                break;
            }
        }
        bool temp=false;
        if(is_sorted(a.begin(),a.end())&&is_sorted(b.begin(),b.end())){
            temp=true;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(b[i]>a[i]){
                ans=-1;
                break;
            }else{
                ans+=a[i]-b[i];
            }
        }
        if(!temp&&ans!=-1)ans+=c;
        cout<<min(ans,ans1)<<endl;
    }
    return 0;
}