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
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            int l=1,h=i+1;
            while(l<=h){
                int mid=l+(h-l)/2; 
                if(arr[i-mid+1]>=mid){
                    l=mid+1;
                }else{
                    h=mid-1;
                }
            }
            cout<<h<<" ";
        }
        cout<<endl;
    }
    return 0;
}