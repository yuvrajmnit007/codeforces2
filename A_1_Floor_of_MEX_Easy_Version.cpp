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
        cin >>n;
        vector<pair<int,int>>vec;
        for (int i=0;i<n;i++){
            int x;
            cin>>x;
            int k=i+1;
            int l=k*x,r=k*(x+1)-1;
            if(l<n){
                r=min(r,n-1);
                vec.push_back({l,r});
            }
        }
        sort(vec.begin(),vec.end());
        vector<int>diff(n+1,0);
        for(auto [l,r]:vec){
            diff[l]++;
            diff[r+1]--;
        }
        vector<int>temp;
        int cur=0;
        for(int i=0;i<n;i++){
            cur+=diff[i];
            if(cur==0){
                temp.push_back(i);
            }
        }
        cout<<temp.size()<<'\n';
        for(int x : temp){
            cout<<x<<' ';
        }
        cout<<'\n';
    }
    return 0;
}