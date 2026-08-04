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
    while(t--){
        int n;
        cin>>n;
        multiset<int>st;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            st.insert(x);
        }
        vector<int>ans;
        int sum=0;
        bool ok=true;
        for(int i=0;i<n;i++){
            int mn=1-sum;
            auto it=st.lower_bound(mn);
            if(it==st.end()){
                ok=false;
                break;
            }
            sum+=*it;
            st.erase(it);
            ans.push_back(sum);
        }
        if(!ok){
            cout<<-1<<endl;
        }else{
            for(auto it:ans){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}