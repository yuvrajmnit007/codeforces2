#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    stack<int>st;
    int n=s.size(); 
    set<int>myset;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push(i);
        }else if(!st.empty()){
            int k=st.top();
            myset.insert(k);
            myset.insert(i);
            st.pop();
        }
    }
    string ans="";
    for(auto it:myset){
        ans+=s[it];
    }
    int res=0;
    int val=0;
    stack<char>st1;
    for(auto it:ans){
        if(it=='('){
            st.push(it);
            val++;
        }else{
            st.pop();
            if(st.empty())res++;
        }
    }
    if(res==0)res=1;
    cout<<val<<" "<<res<<endl;
    return 0;
}