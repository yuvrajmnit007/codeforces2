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
        int odd=0;
        int even=0;
        vector<int>arr(n);
        vector<int>vec(4);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            int val=arr[i]/2;
            if(arr[i]%2==0){
                if(val%2==0)vec[0]++;
                else vec[1]++;
            }else{
                vec[2]++;
            }
        }
        cout<<max({vec[0],vec[1],vec[2]})<<endl;
    }
    return 0;
}