#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int l=0,r=s.size()-1;
    int n=s.size();
    int ans=s.size();
    while(l<=r){
        int k=(l+r)/2;
        bool ok=0;
        for(char c='a';c<='z';c++){
            bool ok1=1;
            int cnt=0;
            for(int i=0;i<k;i++){
                if(s[i]==c){
                    cnt++;
                }
            }
            if(cnt<=0){
                ok1=0;
                continue;
            }
            for(int i=k;i<n;i++){
                if(s[i-k]==c){
                    cnt--;
                }
                if(s[i]==c)cnt++;
                if(cnt<=0){
                    ok1=0;
                    break;
                }
            }
            //cout<<c<<" "<<ok1<<" "<<k<<endl;
            if(ok1){
                ok=1;
                break;
            }
        }
        if(ok){
            ans=k;
            r=k-1;
        }else{
            l=k+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}