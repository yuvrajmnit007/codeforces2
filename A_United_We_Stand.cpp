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
        int mx=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mx=max(mx,arr[i]);
        }
        vector<int>b,c;
        for(int i=0;i<n;i++){
            if(arr[i]!=mx){
                b.push_back(arr[i]);
            }else{
                c.push_back(mx);
            }
        }
        if(b.size()==0||c.size()==0){
            cout<<-1<<endl;
        }else{
            cout<<b.size()<<endl;
            for(auto it:b){
                cout<<it<<" ";
            }
            cout<<endl;
            cout<<c.size()<<endl;
            for(auto it:c){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
