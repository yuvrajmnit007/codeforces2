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
int MOD=998244353;
int f(string s){
    int n=s.size();
    bool pat1=1;
    for(int i=0;i<n;i++){
        char exp=(i%2==0)?'0':'1';
        if(s[i]!='?'&&s[i]!=exp){
            pat1=false;
            break;
        }
    }
    bool pat2=1;
    for(int i=0;i<n;i++){
        char exp=(i%2==0)?'1':'0';
        if(s[i]!='?'&&s[i]!=exp){
            pat2=false;
            break;
        }
    }
    return pat1+pat2;
}
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
        string s1="",s2="";
        for(int i=0;i<n;i++){
            if(i%2==0){
                s1+=s[i];
            }
            else{
                s2+=s[i];
            }
        }
        int ans1=f(s1);
        int ans2=f(s2);
        cout<<(ans1*ans2)%MOD<<endl;
    }
    return 0;
}