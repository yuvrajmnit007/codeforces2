#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>vec(n);
    int g=0;
    int k=0;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        if(vec[i]!=1)k++;
        g=__gcd(g,vec[i]);
    }
    if(k!=n){
        cout<<k<<endl;
        return 0;
    }
    if(g!=1){
        cout<<-1<<endl;
    }else{
        int ans=1e18;
        for(int i=0;i<n-1;i++){
            int val=0;
            for(int j=i;j<n;j++){
                val=__gcd(val,vec[j]);
                if(val==1){
                    ans=min(ans,k-1+j-i);
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}