#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s,t;
        cin>>s>>t;
        int ans=1;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a'].push_back(i);
        }
        int prev=-1;
        for(int i=0;i<t.size();i++){
            if(!mp.count(t[i]-'a')){
                ans=-1;
                break;
            }
            int idx=upper_bound(mp[t[i]-'a'].begin(),mp[t[i]-'a'].end(),prev)-mp[t[i]-'a'].begin();
            if(idx>=mp[t[i]-'a'].size()){
                ans++;
                prev=-1;
                i--;
                continue;
            }
            prev=mp[t[i]-'a'][idx];
        }
        cout<<ans<<endl;
    }
    return 0;
}