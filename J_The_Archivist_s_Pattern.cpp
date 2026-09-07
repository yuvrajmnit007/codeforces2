#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }

    map<int,int>mp1;
    multiset<int>st;
    int ans=0;
    for(auto it:mp){
        st.insert(it.second);
    }
    for(int i=0;i<n;i++){
        auto it1=st.find(mp[arr[i]]);
        mp1[arr[i]]++;
        mp[arr[i]]--;
        if(it1!=st.end())st.erase(*it1);
        st.insert(mp[arr[i]]);
        auto it=st.upper_bound(mp1[arr[i]]);
        if(*it==mp1[arr[i]])it++;
        while(it!=st.end()){
            if(*it==arr[i]){
                int x=mp1[arr[i]]+*it;
                x=(x+1)/2;
                ans+=(x-(mp1[arr[i]]));
                it++;
            }else{
                
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}