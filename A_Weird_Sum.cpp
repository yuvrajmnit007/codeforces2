#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(vector<int>&vec){
    sort(vec.begin(),vec.end());
    int n=vec.size();
    vector<int>pre(n);
    pre[0]=vec[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+vec[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int val=pre[n-1];
        ans+=(val-pre[i]-vec[i]*(n-i-1));
        ans+=(i+1)*vec[i]-pre[i];
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    map<int,vector<pair<int,int>>>mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            mp[grid[i][j]].push_back({i,j});
        }
    }
    int ans=0;
    for(auto [key,vec]:mp){
        vector<int>vec1,vec2;
        for(auto [a,b]:vec){
            vec1.push_back(a);
            vec2.push_back(b);
        }
        ans+=f(vec1);
        ans+=f(vec2);
    }
    cout<<ans/2<<endl;
    return 0;
}