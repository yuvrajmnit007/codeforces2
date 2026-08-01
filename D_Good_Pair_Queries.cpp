/*
██╗   ██╗██╗   ██╗██╗   ██╗██████╗  █████╗      ██╗
╚██╗ ██╔╝██║   ██║██║   ██║██╔══██╗██╔══██╗     ██║
 ╚████╔╝ ██║   ██║██║   ██║██████╔╝███████║     ██║
  ╚██╔╝  ██║   ██║╚██╗ ██╔╝██╔══██║██╔══██║██   ██║
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
        int n,q;
        cin>>n>>q;
        string s1,s2;
        cin>>s1>>s2;
        vector<int>arr1(n+1,0),arr2(n+1,0);
        for(int i=0;i<n;i++){
            arr1[i+1]=arr1[i]+s1[i]-'0';
            arr2[i+1]=arr2[i]+s2[i]-'0';
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            int cnt1=arr1[r]-arr1[l-1];
            int cnt2=arr2[r]-arr2[l-1];
            int len=r-l+1;
            int cnt3=len-cnt1;
            int cnt4=len-cnt2;
            int mx=min(cnt1,cnt2)+min(cnt3,cnt4);
            int diff=abs(cnt1-cnt2);
            if(len%2){
                if(diff<=mx){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }else{
                if(diff<mx||(diff==mx&&!(cnt1==len&&cnt2==0)&&!(cnt1==0&&cnt2==len))){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    return 0;
}