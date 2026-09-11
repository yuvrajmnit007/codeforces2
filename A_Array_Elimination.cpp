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
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        map<int,int>vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                if(arr[i]&(1<<j)){
                    vec[j]++;
                }
            }
        }
        int mn=0;
        for(auto it:vec){
            mn=__gcd(mn,it.second);
        }
        if(mn==0){
            for(int i=0;i<n;i++){
                cout<<i+1<<" ";
            }
            cout<<endl;
        }else{
            vector<int>ans;
            for(int i=1;i*i<=mn;i++){
                if(mn%i==0){
                    ans.push_back(i);
                    if(mn/i!=i){
                        ans.push_back(mn/i);
                    }
                }
            }
            sort(ans.begin(),ans.end());
            for(auto it:ans){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}