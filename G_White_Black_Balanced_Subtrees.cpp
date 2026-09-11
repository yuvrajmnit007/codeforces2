#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,vector<int>>mp;
string s;
int ans=0;
int dfs(int idx){
    if(mp[idx].size()==0){
        if(s[idx-1]=='W')return 1;
        return -1;
    }
    int temp=0;
    for(auto it:mp[idx]){
        temp+=dfs(it);
    }
    if(s[idx-1]=='W')temp++;
    else temp--;
    if(temp==0)ans++;
    return temp;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        ans=0;
        int n;
        cin>>n;
        vector<int>arr(n+1);
        for(int i=2;i<=n;i++){
            cin>>arr[i];
            mp[arr[i]].push_back(i);
        }
        cin>>s;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}