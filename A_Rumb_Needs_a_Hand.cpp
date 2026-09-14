#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>arr(n);
        vector<int>vec;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]-1!=i){
                vec.push_back(arr[i]);
                mp[i]++;
            }
        }
        reverse(vec.begin(),vec.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(mp.count(i)){
                arr[i]=vec[j];
                j++;
            }
        }
        if(is_sorted(arr.begin(),arr.end())){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}