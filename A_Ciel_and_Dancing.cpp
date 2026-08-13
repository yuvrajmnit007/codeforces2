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
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>vec;
    vector<int>boy(n+1,0),girl(m+1,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(boy[i+1]+girl[j+1]==0){
                vec.push_back({i+1,j+1});
                boy[i+1]++;
                girl[j+1]++;
            }else if(boy[i+1]==1&&girl[j+1]==0){
                vec.push_back({i+1,j+1});
                girl[j+1]++;
            }else if(boy[i+1]==0&&girl[j+1]==1){
                vec.push_back({i+1,j+1});
                boy[i+1]++; 
            }
        }
    }
    cout<<vec.size()<<endl;
    for(auto it:vec){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}