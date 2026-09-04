#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<int>a(n);
        vector<int>b(m);
        vector<int>k(n+m+1,0);
        vector<int>freq(n+m+1,0);
        for(int i=0;i<n;i++) {
            cin>>a[i];
            freq[a[i]]=1;
        }
        for(int i=0;i<m;i++) {
            cin>>b[i];
            k[b[i]]++;
        }
        vector<int> c(n+m+1,0);
        int sum=0;
        for(int i=1;i<=n+m;i++){
            if(freq[i]==0){
                continue;
            }
            for(int j=i;j<=n+m;j+=i){
                c[j]++;
            }
            sum++;
        }
        int cnt=0;
        int cnt2=0;
        for(int i=1;i<=n+m;i++){
            if(k[i]==0){
                continue;
            }
            if(c[i]==0){
                cnt+=k[i];
            }
            if(c[i]==sum){
                cnt2+=k[i];
            }
        }
        int l=m-(cnt+cnt2);
        if(l%2==1){
            cnt2++;
        }
        if(cnt2>cnt){
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }
    return 0;
}