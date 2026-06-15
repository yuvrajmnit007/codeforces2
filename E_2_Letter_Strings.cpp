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
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            mp[s]++;
            for(char i='a';i<='k';i++){
                for(char j='a';j<='k';j++){
                    string p=string(1,i)+string(1,j);
                    if(p[0]==s[0]&&s[1]!=p[1]){
                        ans+=mp[p];
                    }else if(p[0]!=s[0]&&s[1]==p[1]){
                        ans+=mp[p];
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}