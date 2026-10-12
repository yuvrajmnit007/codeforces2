#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin>>n;;
        vector<int>arr(n+1);
        map<int,int>mp;
        for(int i=1;i<n+1;i++){
            cin>>arr[i];
            mp[arr[i]]=i;
        }
        vector<int>ans(n+1);
        while(1){
            bool ok=0;
            for(int i=1;i<=n-2;i++){
                int pos1=mp[i],pos2=mp[i+1],pos3=mp[i+2];
                if(pos3<pos2&&pos3<pos1){
                    ok=1;
                    mp[i]=pos3;
                    mp[i+1]=pos1;
                    mp[i+2]=pos2;
                }
            }
            if(!ok)break;
        }
        for(int i=1;i<=n;i++){
            ans[mp[i]]=i;
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}