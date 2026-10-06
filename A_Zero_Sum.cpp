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
        vector<int>vec(n);
        vector<int>arr,arr1;
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        for(int i=0;i<n-1;i+=2){
            if(vec[i]+vec[i+1]==2){
                arr.push_back(i);
            }
            else if(vec[i]+vec[i+1]==-2){
                arr1.push_back(i);
            }
        }
        if(n%2){
            cout<<"NO"<<endl;
            continue;
        }
        if((arr.size()+arr1.size())%2==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}