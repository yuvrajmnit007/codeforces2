#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n+1,0);
    vector<pair<int,int>>vec;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        arr[u]++;
        arr[v]++;
        vec.push_back({u,v});
    }
    int val=0;
    vector<int>ans(n-1,-1);
    for(int i=1;i<n+1;i++){
        if(arr[i]>=3){
            for(int j=0;j<vec.size();j++){
                int u=vec[j].first;
                int v=vec[j].second;
                if(u==i||v==i){
                    ans[j]=val;
                    val++;
                }
            }
            break;
        }
    }
    for(int i=0;i<n-1;i++){
        if(ans[i]==-1){
            ans[i]=val;
            val++;
        }
    }
    for(auto it:ans){
        cout<<it<<endl;
    }
    return 0;
}