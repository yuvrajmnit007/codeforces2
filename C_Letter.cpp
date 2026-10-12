#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.size();
    vector<int>vec1(n),vec2(n);
    if(s[0]-'a'>=0&&s[0]-'a'<=26)vec1[0]=1;
    for(int i=1;i<n;i++){
        vec1[i]=vec1[i-1];
        if(s[i]-'a'>=0&&s[i]-'a'<=26){
            vec1[i]++;
        }
    }
    if(s[n-1]-'A'>=0&&s[n-1]-'A'<=26)vec2[n-1]=1;
    for(int i=n-2;i>=0;i--){
        vec2[i]=vec2[i+1];
        if(s[i]-'A'>=0&&s[i]-'A'<=26){
            vec2[i]++;
        }
    }
    int ans=1e18;
    for(int i=0;i<n-1;i++){
        ans=min(ans,vec1[i]+vec2[i+1]);
    }
    ans=min(ans,vec1[n-1]);
    ans=min(ans,vec2[0]);
    cout<<ans<<endl;
    return 0;
}