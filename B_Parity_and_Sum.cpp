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
        vector<int>odd,even;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2)odd.push_back(arr[i]);
            else even.push_back(arr[i]);
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        int ans=0;
        if(even.size()==0||odd.size()==0){
            cout<<0<<"\n";
            continue;
        }
        int mx=odd.back();
        int i=0;
        int sum=mx;
        while(i<even.size()&&even[i]<sum){
            sum+=even[i];
            i++;
        }
        if(i==even.size()){
            cout<<even.size()<<"\n";
            continue;
        }else{
            cout<<even.size()+1<<"\n";
        }
    }
    return 0;
}