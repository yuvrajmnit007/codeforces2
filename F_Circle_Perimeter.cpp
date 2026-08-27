#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int ans=0;
        for(int i=0;i<=n;i++){
            int k=n*n-i*i;
            int p=(n+1)*(n+1)-(i*i)-1;
            int val=floor(sqrt(p))-ceil(sqrt(k))+1;
            if(i==0||i==n)val--;
            ans+=val;
        }
        cout<<4*ans+4<<endl;
    }
    return 0;
}