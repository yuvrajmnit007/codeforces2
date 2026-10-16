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
        vector<int>vec;
        int i=0;
        while(i<n-1){
            int j=i+1;
            if(arr[i]<arr[j]){
                while(j<n&&arr[j]>arr[j-1]){
                    j++;
                }
                vec.push_back(arr[i]);
                vec.push_back(arr[j-1]);
            }else{
                while(j<n&&arr[j]<arr[j-1]){
                    j++;
                }
                vec.push_back(arr[i]);
                vec.push_back(arr[j-1]);
            }
            i=j-1;
        }
        vector<int>ans;
        ans.push_back(vec[0]);
        for(int k=1;k<vec.size();k++){
            if(vec[k]!=vec[k-1]){
                ans.push_back(vec[k]);
            }
        }
        cout<<ans.size()<<endl;
        for(int k=0;k<ans.size();k++){
            cout<<ans[k]<<" ";
        }
        cout<<endl;
    }
    return 0;
}