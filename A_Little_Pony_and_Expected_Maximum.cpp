#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    double ans=0.0;
    for(int i=1;i<=m;i++){
        double val1=(i*1.0/m*1.0);
        double val2=((i-1)*1.0/m*1.0);
        ans+=(i*(pow(val1,n)-pow(val2,n)));
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}