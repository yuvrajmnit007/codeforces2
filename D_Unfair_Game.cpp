#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<vector<int>>ncr(32,vector<int>(32));
    for(int i=0;i<32;i++){
        for(int j=0;j<32;j++){
            if(i<j){
                ncr[i][j]=0;
            }else if(j==0){
                ncr[i][j]=1;
            }else{
                ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
            }
        }
    }
    while (t--) {
        int n,k;
        cin>>n>>k;
        int p=0;
        while(n>1){
            n/=2;
            p++;
        }
        int ans=0;
        for(int i=0;i<p;i++){
            for(int j=1;j<=i+1;j++){
                if(i+j<=k)continue;
                else{
                    ans+=ncr[i][j-1];
                }
            }
        }
        if(p+1>k)ans++;
        cout<<ans<<endl;
    }
    return 0;
}