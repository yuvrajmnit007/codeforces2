#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while (t--) {
        int n,k;cin>>n>>k;
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        vector<int>arr(n,0);
        while(k--){
            int l,r;
            cin>>l>>r;
            l--,r;
            arr[l]+=1;
            if(r<n)arr[r]+=-1;
        }
        for(int i=1;i<n;i++){
            arr[i]=arr[i-1]+arr[i];
        }
        sort(arr.rbegin(),arr.rend());
        sort(vec.rbegin(),vec.rend());
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(arr[i]*vec[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}