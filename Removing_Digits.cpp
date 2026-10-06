#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int n){
    int ans=0;
    while(n>0){
        ans=max(ans,n%10);
        n/=10;
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ans=0;
    while(n>0){
        ans++;
        n-=f(n);
    }
    cout<<ans<<endl;
    return 0;
}