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
        string s;
        cin>>s;
        vector<char>vec;
        int one=1,zero=1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'&&!one){
                vec.push_back('1');
                one=0;
            }else if(s[i]=='0'&&!zero){
                vec.push_back('0');
                zero=0;
            }else if(s[i]=='1'&&one){
                one=0;
            }else if(s[i]=='0'&&zero){
                zero=0;
            }
        }
        for(auto it:vec){
            cout<<it;
        }
        cout<<endl;
    }
    return 0;
}