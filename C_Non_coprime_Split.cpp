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
        int l,r;
        cin>>l>>r;
        if(r%2==0&&r!=2){
            cout<<r/2<<" "<<r/2<<endl;
        }else if(((r-1)>=max(4LL,l))){
            cout<<(r-1)/2<<" "<<(r-1)/2<<endl;
        }else{
            bool ok=0;
            int k=r;
            map<int,int>mp;
            for(int i=2;i*i<=r;i++){
                while(r%i==0){
                    mp[i]++;
                    r/=i;
                }
                if(mp[i]>=1){
                    if(k-i<=1)continue;
                    cout<<i<<" "<<k-i<<endl;
                    ok=1;
                    break;
                }
            }
            if(!ok)cout<<-1<<endl;
        }
    }
    return 0;
}