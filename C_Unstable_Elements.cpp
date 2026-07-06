#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        map<int,int>mp;
        for (int i=0;i<n;i++){
            cin >> arr[i];
            mp[arr[i]]++;
        }
        vector<int>freq;
        for (auto it : mp){
            freq.push_back(it.second);
        }
        map<int,int>mp1;
        for (int x : freq){
            mp1[x]++;
        }
        int val1=n;
        int val2=freq.size();
        int ans=0;
        for(auto it:mp1){
            int next=it.first;
            if(val2>0){
                int diff=k-val1;
                if(diff%val2==0){
                    if(diff/val2+next>=1){
                        ans++;
                    }
                }
            }
            val2-=it.second;
            val1-=it.first*it.second;
        }
        cout<<ans<<endl;
        }
    return 0;
}