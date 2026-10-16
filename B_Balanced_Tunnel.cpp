#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>a(n),b(n),pos(n+1);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        cin>>b[i];
        pos[b[i]]=i;
    }
    int ans=0,mx=-1;
    for(int i=0;i<n;i++){
        if(pos[a[i]]<mx) ans++;
        mx=max(mx,pos[a[i]]);
    }
    cout<<ans<<endl;
    return 0;
}