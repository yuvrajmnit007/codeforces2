#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(string &s){
    int ans=0;
    for(auto it:s){
        ans*=10;
        ans+=(it-'0');
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    set<int> st;
    stack<string> s;

    vector<int> ans;

    while(m--) {
        string str;
        cin >> str;

        if(str == "IN") {
            string ch;
            cin >> ch;

            // if(ch == "?") {
            //     int val=1;
            //     while(st.find(val)!=st.end())val++;
            //     s.push(val);
            //     st.insert(val);
            // }
            // else {
            //     s.push(f(ch));
            //     if(st.find(f(ch))==st.end())st.insert(f(ch));
            //     else {
            //         cout<<"invalid"<<endl;
            //         return 0;
            //     }
            s.push(ch);
            if(ch!="?"){
                int val=f(ch);
                st.insert(val);
            }

        }else{
            if(s.empty()){
                cout<<"invalid"<<endl;
                return 0;
            }
            string xyz=s.top();
            s.pop();
            if(xyz=="?"){
                int val=1;
                while(st.find(val)!=st.end())val++;
                st.insert(val);
                ans.push_back(val);
            }else{
                ans.push_back(f(xyz));
            }
        }
    }
    for(auto it:ans){
        cout<<it<<endl;
    }
    
    return 0;
}