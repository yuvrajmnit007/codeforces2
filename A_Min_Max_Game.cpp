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
        vector<int>a(n);
        int o=0;
        int z=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1){
                o++;
            }
            else{
                z++;
            }
        }
        if(o>=z){
            cout<<"Bessie"<<endl;
        }
        else{
            cout<<"Elsie"<<endl;
        }
    }
    return 0;
}