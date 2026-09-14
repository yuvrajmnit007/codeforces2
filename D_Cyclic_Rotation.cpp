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
        vector<int>arr(n);
        vector<int>brr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            cin>>brr[i];
        }
        int i=n-1,j=n-1;
        multiset<int>st;
        bool ok=1;
        while(i>=0&&j>=1){
            if(brr[j]==brr[j-1]){
                st.insert(brr[j]);
                j--;
            }
            else if(arr[i]==brr[j]){
                i--;
                j--;
            }else{
                if(st.find(arr[i])==st.end()){
                    ok=0;
                    break;
                }else{
                    auto it=st.find(arr[i]);
                    st.erase(it);
                    i--;
                }
            }
        }
        if(!ok||j>0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}