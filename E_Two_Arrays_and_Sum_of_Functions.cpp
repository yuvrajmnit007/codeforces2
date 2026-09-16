#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=998244353;
void print128(__int128 x){
    if(x<0){
        cout<<'-';
        x=-x;
    }
    if(x>9)print128(x/10);
    cout<<(char)('0'+(x%10));
}
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
    for(int i=0;i<n;i++){
        a[i]=a[i]*(n-i)*(i+1);
    }
    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());
    __int128 ans=0;
    for(int i=0;i<n;i++){
        ans=(ans+(__int128)a[i]*b[i])%MOD;
    }
    print128(ans);
    return 0;
}