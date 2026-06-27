#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=998244353;
int f(int x,int y){
    if(y==0)return 1;
    if(y%2==0){
        int temp=f(x,y/2);
        return (temp*temp)%MOD;
    }else{
        return (x*f(x,y-1))%MOD;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,m,r,c;
        cin>>n>>m>>r>>c;
        int ans=0;
        int exp=n*m-(n-r+1)*(m-c+1);
        cout<<f(2,exp)<<endl;
    }
    return 0;
}