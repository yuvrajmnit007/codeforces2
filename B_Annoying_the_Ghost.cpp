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
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int ans=0;
        bool ok=1;
        for(int i=0;i<n;i++){
            if(a[i]>b[i]){
                int j;
                for(j=i+1;j<n;j++){
                    if(a[j]<=b[i])break;
                }
                if(j==n){
                    ok=0;
                    break;
                }
                ans+=(j-i);
                while(j>i){
                    swap(a[j],a[j-1]);
                    j--;
                }
            }
        }
        if(ok){
            cout<<ans<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}