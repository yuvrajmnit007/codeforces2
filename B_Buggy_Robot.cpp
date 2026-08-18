#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=0,r=0,u=0,d=0;
    for(int i=0;i<n;i++){
        if(s[i]=='L')l++;
        if(s[i]=='R')r++;
        if(s[i]=='U')u++;
        if(s[i]=='D')d++;
    }
    cout<<2*min(l,r)+2*min(u,d)<<endl;
    return 0;
}