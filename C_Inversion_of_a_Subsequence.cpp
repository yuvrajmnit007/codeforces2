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
        vector<int>vec1(n),vec2(n);
        int cnt1=0,cnt0=0;
        for(int i=0;i<n;i++){
            cin>>vec1[i];
            cnt1+=vec1[i];
        }
        for(int i=0;i<n;i++){
            cin>>vec2[i];
            if(vec2[i]==0)cnt0++;
        }
        int sum=0;
        bool ok=1;
        for(int i=0;i<n;i++){
            if(vec1[i]!=vec2[i]){
                sum+=vec1[i];
                ok=0;
            }
        }
        if(ok){
            cout<<0<<endl;
        }else if(cnt1==0||cnt0==0){
            cout<<-1<<endl;
        }else if(sum%2==1){
            cout<<1<<endl;
        }else{
            cout<<2<<endl;
        }
    }
    return 0;
}