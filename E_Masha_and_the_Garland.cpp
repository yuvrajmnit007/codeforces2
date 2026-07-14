#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int>prefix(n,0);
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                prefix[i]=prefix[i-1]+1;
            }else{
                prefix[i]=prefix[i-1];
            }
        }
        for(int i=0;i<k;i++){
            int l,r,u;
            cin>>l>>r>>u;
            if((prefix[r-1]-prefix[l-1]+1)/2<=u){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}