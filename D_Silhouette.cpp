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
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]].push_back(i);
        }
        vector<pair<int,int>>vec;
        for(auto it:mp){
            vec.push_back({it.first,it.second.size()});
        }
        if(vec[0].first!=0){
            cout<<-1<<endl;
            continue;
        }
        vector<int>ans(n);
        bool flag=false;
        int prev=0;
        for(int i=1;i<vec.size();i++){
            int sz=vec[i-1].second;
            int diff=vec[i].first-vec[i-1].first;
            if(diff%sz!=0){
                flag=true;
                break;
            }
            int val=diff/sz;
            if(val<=prev){
                flag=true;
                break;
            }
            prev=val;
            for(auto it:mp[vec[i-1].first]){
                ans[it]=val;
            }
        }
        if(flag){
            cout<<-1<<endl;
        }else{
            int last=prev+1;
            for(auto it:mp[vec.back().first]){
                ans[it]=last;
            }
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}