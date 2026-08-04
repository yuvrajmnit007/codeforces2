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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans=0;
        int i=0;
        string s1="";
        bool flag=false,flag1=false;
        while(i<n){
            int j=i;
            while(j<n&&s[j]==s[i]){
                j++;
            }
            ans++;
            s1+=s[i];
            if(j-i==1&&i>0&&i<n-1){
                flag1=true;
            }
            i=j;
        }
        for(int i=1;i<n-1;i++){
            if(s[i-1]!=s[i]&&s[i]!=s[i+1]&&s[i-1]==s[i+1]){
                flag=true;
                break;
            }
        }
        if(flag)ans-=2;
        else if(flag1)ans--;
        cout<<ans<<endl;
    }
    return 0;
}