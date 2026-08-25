#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    set<int>st;
    int pdt=1;
    for(int i=1;i<n;i++){
        if(__gcd(i,n)==1){
            st.insert(i);
            pdt*=i;
            pdt%=n;
        }
    }
    if(pdt!=1){
        st.erase(pdt);
    }
    cout<<st.size()<<endl;
    for(auto it:st){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}