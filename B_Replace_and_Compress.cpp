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
        int n=s.size();
        bool isone=0,isthree=0;
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i+1]){
                if(s[i]==s[i-1])isthree=1;
                else isone=1;
            }
        }
        cout<<isone+isthree+1<<endl;
    }
    return 0;
}