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
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(is_sorted(arr.begin(),arr.end())){
            cout<<"Bob"<<endl;
            continue;
        }
        bool ok=1;;
        vector<int>vec;
        for(int i=0;i<n;i++){
            set<int>st;
            if(arr[i]==1){
                vec.push_back(1);
                continue;
            }
            for(int j=2;j*j<=arr[i];j++){
                if(arr[i]%j==0){
                    st.insert(j);
                    while(arr[i]%j==0){
                        arr[i]/=j;
                    }
                }
            }
            if(arr[i]>1){
                st.insert(arr[i]);
            }
            if(st.size()>=2){
                ok=0;
                break;
            }else{
                vec.push_back(*st.begin());
            }
        }
        if(ok&&is_sorted(vec.begin(),vec.end())){
            cout<<"Bob"<<endl;
        }else{
            cout<<"Alice"<<endl;
        }
    }
    return 0;
}