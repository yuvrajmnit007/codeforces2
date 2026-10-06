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
        int cnt0=0,cnt1=0;
        for(auto it:s){
            if(it=='0')cnt0++;
            else cnt1++;
        }
        if(abs(cnt0-cnt1)>=3){
            cout<<-1<<endl;
            continue;
        }
        int len=1;
        int l0=0,l1=0;
        if(s[0]=='0')l0++;
        else l1++;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                len++;
                if(s[i]=='0')l0++;
                else l1++;
            }
        }
        cout<<n-len+max(abs((l0-l1)-(cnt0-cnt1))-1,0LL)<<endl;
    }
    return 0;
}