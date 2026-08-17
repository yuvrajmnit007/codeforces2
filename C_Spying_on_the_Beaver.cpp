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
        vector<int>arr(n+1);
        unordered_map<int,vector<int>>adj;
        for(int i=2;i<=n;i++){
            cin>>arr[i];
            adj[arr[i]].push_back(i);
        }
        int m;
        cin>>m;
        map<int,int>mp;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            mp[x]=1;
        }
        map<int,int>mp1;
        for(int i=n;i>=1;i--){
            if(mp[i]==1)mp1[i]=1;
            for(auto it:adj[i]){
                if(mp1[it]==1){
                    mp1[i]=1;
                }
            }
        }
        vector<int>ans;
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(auto it:adj[i]){
                if(mp1[it]==1){
                    cnt++;
                }
            }
            if(mp[i]==1){
                if(cnt>=1){
                    for(auto it:adj[i]){
                        if(mp1[it]==1){
                            ans.insert(it);
                        }
                    }
                }
            }else{
                if(cnt>1){
                    for(auto it:adj[i]){
                        if(mp1[it]==1){
                            ans.insert(it);
                        }
                    }
                }
            }
        }
        cout<<ans.size()<<" ";
        for(int it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}