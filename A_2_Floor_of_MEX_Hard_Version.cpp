#include <bits/stdc++.h>
using namespace std;
constexpr int md = int(1e9) + 7;
using int = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
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
        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }
        for(auto it:diff){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}