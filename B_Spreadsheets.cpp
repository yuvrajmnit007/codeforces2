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
        string a="",b="";
        int n=s.size();
        int i=n-1;
        while(i>=0){
            if('0'<=s[i]&&s[i]<='9'){
                a+=s[i];
            }else break;
            i--;
        }
        reverse(a.begin(),a.end());
        if(i-1>=0&&('0'<=s[i-1]&&s[i-1]<='9')){
            i--;
            while(i>=0){
                if('0'<=s[i]&&s[i]<='9'){
                    b+=s[i];
                }else break;
                i--;
            }
            reverse(b.begin(),b.end());
        }else{
            while(i>=0){
                b+=s[i];
                i--;
            }
            int ans=0;
            reverse(b.begin(),b.end());
            for(auto c:b){
                ans*=26;
                ans+=(c-'A'+1);
            }
            cout<<"R"<<a<<"C"<<ans<<endl;
            continue;
        }
        string ans="";
        int k=stoi(a);
        while(k>0){
            k--;
            int rem=k%26;
            k/=26;
            ans+=('A'+rem);
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<b<<endl;
    }
    return 0;
}