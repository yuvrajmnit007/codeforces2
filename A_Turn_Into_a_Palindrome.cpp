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
        char c;
        string s;
        cin>>n>>c>>s;
        int i=0,j=n-1;
        int ans=0;
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }else{
                if(s[i]!=c){
                    ans++;
                }
                if(s[j]!=c){
                    ans++;
                }
                i++;
                j--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}