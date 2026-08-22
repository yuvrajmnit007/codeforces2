#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,x,y;
        cin>>n>>x>>y;
        vector<int>vec(n);
        vector<int>vec1,vec2;
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        for(int i=0;i<x;i++){
            vec1.push_back(vec[i]);
        }
        for(int i=x;i<y;i++){
            vec2.push_back(vec[i]);
        }
        for(int i=y;i<n;i++){
            vec1.push_back(vec[i]);
        }
        int k=vec2.size();
        int idx=0;
        int mn=1e18;
        for(int i=0;i<k;i++){
            vec2.push_back(vec2[i]);
            if(vec2[i]<mn){
                idx=i;
                mn=vec2[i];
            }
        }
        vector<int>ans;
        int i=0;
        while(i<vec1.size()&&vec1[i]<vec2[idx]){
            ans.push_back(vec1[i]);
            i++;
        }
        for(int j=idx;j<idx+k;j++){
            ans.push_back(vec2[j]);
        }
        while(i<vec1.size()){
            ans.push_back(vec1[i]);
            i++;
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}