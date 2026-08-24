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
        int cnt0=0,cnt1=0;
        int ans=1e18;
        int i=0;
        bool turn=0;
        while(i<n){
            if(!turn){
                while(i<n&&s[i]=='1'){
                    cnt1++;
                    i++;
                }
                turn=1;
            }else{
                while(i<n&&s[i]=='0'){
                    cnt0++;
                    i++;
                }
                turn=0;
            }
        }
        if(abs(cnt1-cnt0)<=1){
            ans=min(ans,cnt1+cnt0);
        }
        cnt0=0,cnt1=0;
        turn=1;
        while(i<n){
            if(!turn){
                while(i<n&&s[i]=='1'){
                    cnt1++;
                    i++;
                }
                turn=1;
            }else{
                while(i<n&&s[i]=='0'){
                    cnt0++;
                    i++;
                }
                turn=0;
            }
        }
        if(abs(cnt1-cnt0)<=1){
            ans=min(ans,cnt1+cnt0);
        }
        if(ans==1e18){
            cout<<-1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
    return 0;
}