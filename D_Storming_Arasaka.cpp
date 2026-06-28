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
        vector<pair<int,int>>vec;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                int cnt=0;
                while(n%i==0){
                    n/=i;
                    cnt++;
                }
                vec.push_back({i,cnt});
            }
        }
        if(n>1)vec.push_back({n,1});
        int ans=0;
        for(auto it:vec){
            ans+=it.second;
        }
        cout<<ans+(int)vec.size()-1<<endl;
    }
    return 0;
}