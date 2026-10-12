#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        stack<int>st;
        int j=1;
        vector<int>vec(n+1,0);
        for(int i=0;i<n;i++){
            if(s[i]=='3'){
                vec[i+1]=1;
                continue;
            }
            if(s[i]=='2'){
                if(st.empty()){
                    vec[i+1]=1;
                }else{
                    vec[st.top()]=1;
                    st.pop();
                }
            }
            if(s[i]=='1'){
                st.push(i+1);
            }
        }
        int ans=0;
        for(auto it:vec){
            if(it==0)ans++;
        }
        cout<<ans-1<<endl;
        for(int i=1;i<=n;i++){
            if(vec[i]==0){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}