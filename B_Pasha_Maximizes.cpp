/*
██╗   ██╗██╗   ██╗██╗   ██╗██████╗  █████╗      ██╗
╚██╗ ██╔╝██║   ██║██║   ██║██╔══██╗██╔══██╗     ██║
 ╚████╔╝ ██║   ██║██║   ██║██████╔╝███████║     ██║
  ╚██╔╝  ██║   ██║╚██╗ ██╔╝██╔══██╗██╔══██║██   ██║
   ██║   ╚██████╔╝ ╚████╔╝ ██║  ██║██║  ██║╚█████╔╝
   ╚═╝    ╚═════╝   ╚═══╝  ╚═╝  ╚═╝╚═╝  ╚═╝ ╚════╝
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    string s=to_string(n);
    string ans="";
    for(int i=0;i<s.size();i++){
        int idx=i,val=s[i]-'0';
        for(int j=i;j<min((int)s.size(),i+k+1);j++){
            if((s[j]-'0')>val){
                val=s[j]-'0';
                idx=j;
            }
        }
        ans+=to_string(val);
        k-=(idx-i);
        s.erase(s.begin()+idx);
        i--;
    }
    ans+=s;
    cout<<ans<<endl;
    return 0;
}