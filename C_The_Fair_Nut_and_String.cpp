#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD=1e9+7;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.size();
    vector<int>vec;
    int val=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a')val++;
        if(s[i]=='b'){
            vec.push_back(val);
            val=0;
        }
    }
    if(val!=0){
        vec.push_back(val);
    }
    int ans=1;
    for(auto it:vec){
        ans*=it+1;
        ans%=MOD;
    }
    cout<<ans-1<<endl;
    return 0;
}