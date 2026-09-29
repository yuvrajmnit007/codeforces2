/*solution bda simple he ki at the end sare agar equal hojate he to ek kaam kro max operation  
jitne ho sakte he kar do fir uske baad compare kar lo that will be answer . also ek operation ke baad max value 
999999999 ->729 ho sakti he so jyda operations nhi karne padenge at the end cycle to aani he so lets take ki 
900 ya 1000 oprations ke baad sab equal ho jayenge 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int k){
    int ans=0;
    while(k>0){
        ans+=(k%10)*(k%10);
        k/=10;
    }
    return ans;
}
int ncr(int n){
    if(n<2)return 0;
    return n*(n-1)/2;
}
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
            for(int j=0;j<=1000;j++){
                arr[i]=f(arr[i]);
            }
        }
        sort(arr.begin(),arr.end());
        // for(auto it:arr){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        int ans=0;
        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n&&arr[i]==arr[j])j++;
            ans+=(ncr(j-i));
            i=j;
        }
        cout<<ans<<endl;
    }
    return 0;
}