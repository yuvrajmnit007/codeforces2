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
        vector<int>vec1(n),vec2(n);
        int one=0,two=0,three=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==1)one++;
            else if(arr[i]==2)two++;
            else three++;
            vec1[i]=one-two-three;
            vec2[i]=one+two-three;
        }
        bool ok=0;
        int mn=1e18;
        for(int i=1;i<n-1;i++){
            if(vec1[i-1]>=0){
                mn=min(mn,vec2[i-1]);
            }
            if(mn<=vec2[i]){
                ok=1;
                break;
            }
        }
        if(ok){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}