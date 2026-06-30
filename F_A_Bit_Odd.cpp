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
        int one=-1,zero=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                one=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                zero=i;
                break;
            }
        }
        bool ans=false;
        if(one!=-1&&zero!=-1&&one<zero){
            int i=one;
            while(i<=zero){
                int j=i;
                while(j<=zero&&s[j]==s[i]){
                    j++;
                }
                if((j-i)%2){
                    ans=true;
                    break;
                }
                i=j;
            }
        }
        if(ans){
            cout<<"Alice"<<endl;
        }else{
            cout<<"Bob"<<endl;
        }
    }
    return 0;
}