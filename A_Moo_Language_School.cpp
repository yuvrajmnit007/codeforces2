#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(string &st){
    int cnt=0;
    for(auto it:st){
        if(it=='1')cnt++;
    }
    return cnt==(int)st.size();
}
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
        int ans=0;
        for(int i=0;i<n/k;i++){
            string st=s.substr(i*k,k);
            if(check(st))ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}