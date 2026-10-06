#include <bits/stdc++.h>
using namespace std;
#define int long long
int sum(int k){
    int val=0;
    while(k>0){
        val+=(k%10);
        k/=10;
    }
    return val;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ans=19;
    int i=1;
    while(i!=n){
        ans+=9;
        if(sum(ans)==10){
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}