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
        int pdt=1;
        for(int i=0;i<n;i++){
            pdt=(pdt/__gcd(pdt,arr[i]))*arr[i];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(pdt/arr[i]);
        }
        if(sum>=pdt){
            cout<<-1<<endl;
        }else{
            for(auto it:arr){
                cout<<pdt/it<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}