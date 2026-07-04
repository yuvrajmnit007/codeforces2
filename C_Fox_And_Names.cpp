#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string ans="";
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int sz=ans.size();
        if(sz>0&&s[0]!=ans[sz-1]){
            ans+=s[0];
        }else if(sz==0){
            ans+=s[0];
        }else{
            
        }
    }
    vector<int>vec(26,0);
    for(auto c:ans){
        vec[c-'a']++;
        if(vec[c-'a']>1){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    string ans1="";
    for(int i=0;i<26;i++){
        if(vec[i]==0){
            ans1+=('a'+i);
        }
    }
    int i=0,j=0;
    string ans2="";
    while(i<ans1.size()&&j<ans.size()){
        if(ans1[i]<ans[j]){
            ans2+=ans1[i];
            i++;
        }else{
            ans2+=ans[j];
            j++;
        }
    }
    while(i<ans1.size()){
        ans2+=ans1[i];
        i++;
    }
    while(j<ans.size()){
        ans2+=ans[i];
        j++;
    }
    cout<<ans2<<endl;
    return 0;
}


