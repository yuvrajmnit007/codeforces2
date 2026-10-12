#include <bits/stdc++.h>
using namespace std;
#define int long long
int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        if(n<4){
            cout<<1<<endl;
        }else{
            int cnt=0;
            int temp=n;
            while(temp>=4){
                cnt++;
                temp/=4;
            }
            cout<<power(2,cnt)<<endl;
        }
    }
    return 0;
}