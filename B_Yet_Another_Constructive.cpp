#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k,m;
        cin>>n>>k>>m;
        if(m<k){
            cout<<"NO"<<endl;
            continue;
        }else{
            int j=1;
            vector<int>ans;
            for(int i=0;i<n;i++){
                if(j<k){
                    ans.push_back(1);
                    j++;
                }else{
                    ans.push_back(m-k+1);
                    j=1;
                }
            }  
            cout<<"YES"<<endl;
            for(auto it:ans){
                cout<<it<<" ";
            } 
            cout<<endl;
        }
    }
    return 0;
}