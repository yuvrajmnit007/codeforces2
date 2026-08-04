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
        string s1,s2;
        cin>>s1>>s2;
        vector<int>vec1,vec2,vec3,vec4;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(s1[i]=='1')vec1.push_back(i);
                if(s2[i]=='1')vec2.push_back(i);
            }else{
                if(s1[i]=='1')vec3.push_back(i);
                if(s2[i]=='1')vec4.push_back(i);
            }
        }
        if(vec1.size()!=vec2.size()||vec3.size()!=vec4.size()){
            cout<<"NO"<<endl;
            continue;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}