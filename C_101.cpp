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
        int first=-1,last=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]==-1||arr[i]==1){
                last=i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(first==-1&&(arr[i]==1||arr[i]==-1)){
                first=i;
                arr[i]=1;
            }else if(i<last&&arr[i]==-1){
                arr[i]=0;
            }else if(arr[i]==-1){
                arr[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}