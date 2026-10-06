#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        string s1;
        cin>>s1;
        string s='L'+s1+'L';
        bool ans=1;
        int i=0;
        while(i<n+1){
            int j=i+1;
            while(j<n+2&&s[j]!='L')j++;
            if(j-i<=m){
                i=j;
            }else{
                i+=m;
                while(i<j){
                    if(s[i]=='C'||k==0){
                        ans=0;
                        break;
                    }
                    k--;
                    i++;
                }
                if(!ans)break;
            }
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}