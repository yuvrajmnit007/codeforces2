#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>>arr(n);
    int mn=1e18,mx=-1e18;
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        mn=min(mn,arr[i].first);
        mx=max(mx,arr[i].second);
    }
    for(int i=0;i<n;i++){
        if(arr[i].first==mn&&arr[i].second==mx){
            cout<<i+1<<"\n";
            return 0;
        }
    }
    cout<<-1<<"\n";
    return 0;
}