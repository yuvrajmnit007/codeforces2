#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        vec.push_back({l,1});
        vec.push_back({r+1,-1});
    }
    sort(vec.begin(),vec.end());
    int sum=0;
    bool ok=1;
    for(int i=0;i<vec.size();i++){
        sum+=vec[i].second;
        if(sum>2){
            ok=0;
            break;
        }
    }
    if(ok){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}