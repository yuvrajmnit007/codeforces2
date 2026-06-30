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
        string s;
        cin>>s;
        int temp=0;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                temp++;
            }
        }
        if(temp==1)cout<<2<<endl;
        else{
            cout<<1<<endl;
        }
    }
    return 0;
}