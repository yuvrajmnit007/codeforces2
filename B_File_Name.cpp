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
    int ans=0;
    int i=0;
    while(i<n){
        int j=i;
        while(s[j]=='x'){
            j++;
        }
        if(j>i){
            if(j-i+1>=3){
                ans+=(j-i+1-3);
            }
            i=j;
        }else{
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}