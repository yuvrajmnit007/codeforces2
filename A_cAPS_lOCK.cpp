#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    bool ok=true;
    int n=s.size();
    for(int i=1;i<n;i++){
        if(islower(s[i])){
            ok = false;
            break;
        }
    }
    if(ok){
        for(int i=0;i<s.size();i++){
            if(islower(s[i])){
                s[i]=toupper(s[i]);
            }
            else{

                s[i]=tolower(s[i]);
            }
        }
    }
    cout<<s<<endl;
    return 0;
}