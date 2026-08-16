#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n);
    int cnt=0;
    unsigned __int128 sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        if(arr[i]%2==1)cnt++;
    }
    sort(arr.rbegin(),arr.rend());
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            cout<<-1<<endl;
            return 0;
        }
    }
    if(cnt!=1){
        cout<<-1<<endl;
        return 0;
    }
    unsigned __int128 target=sum+1;
    if((sum&target)==0&&target>0){
        int ans=0;
        unsigned __int128 temp=target;
        while(temp>1){
            temp>>=1;
            ans++;
        }
        cout<<ans<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}