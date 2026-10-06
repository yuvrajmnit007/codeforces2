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
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        int i=0;
        while(i<n){
            for(auto it=mp.rbegin();it!=mp.rend();++it) { 
                if(it->second>0) { 
                    cout<<it->first<<" "; 
                    it->second--;
                    i++; 
                } 
            }   
        }
        cout<<"\n";
    }
    return 0;
}