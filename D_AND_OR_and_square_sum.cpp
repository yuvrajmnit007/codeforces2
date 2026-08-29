#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n),vec(21,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        int x=arr[i];
        for(int i=0;i<=20;i++){
            vec[i]+=(x>>i)&1;
        }
    }
    int ans=0;
    while(1){
        int x=0;
        for(int i=20;i>=0;i--){
            x=x<<1;
            if(vec[i]>=1){
                x+=1;
                vec[i]--;
            }
        }
        if(x==0)break;
        ans+=(x*x);
    }
    cout<<ans<<endl;
    return 0;
}