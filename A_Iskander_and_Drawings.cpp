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
        int mx=0;
        string s;
        cin>>s;
        int i=0;
        while(i<n){
            int j=i;
            int temp=0;
            while(j<n&&s[j]=='#'){
                temp++;
                j++;
            }
            i=j+1;
            mx=max(mx,temp);
        }
        if(mx==1||mx==2){
            cout<<1<<endl;
        }else{
            cout<<(mx+1)/2<<endl;
        }
    }
    return 0;
}