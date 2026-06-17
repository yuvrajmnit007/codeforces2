#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int n=t;
    vector<pair<string,int>>vec;
    map<string,int>mp;
    while (t--) {
        string s;
        int p;
        cin>>s>>p;
        vec.push_back({s,p});
        mp[s]+=p;
    }
    int m=-1e6;
    for(auto it:mp){
        m=max(m,it.second);
    }
    vector<string>win;
    for(auto it:mp){
        if(it.second==m){
            win.push_back(it.first);
        }
    }
    if(win.size()==1){
        cout<<win[0]<<endl;
    }else{
        map<string,int>mp1;
        for(int i=0;i<n;i++){
            string name=vec[i].first;
            int point=vec[i].second;
            mp1[name]+=point;
            bool ok=false;
            for(auto it:win){
                if(name==it){
                    ok=true;
                    break;
                }
            }
            if(ok&&mp1[name]>=m){
                cout<<name<<endl;
                break;
            }
        }
    }
    return 0;
}