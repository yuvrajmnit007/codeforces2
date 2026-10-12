#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int>arr(n);
   for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n<=2){
        cout<<0<<endl;
        return 0;
    }
    int ans=1e18;
    for(int x=-1;x<=1;x++){
        for(int y=-1;y<=1;y++){
            int first=arr[0]+x;
            int second=arr[1]+y;
            int d=second-first;
            int cnt=abs(x)+abs(y);
            for (int i=2;i<n;i++){
                int expected=first+i*d;
                if(arr[i]==expected){
                    continue;
                }else if(arr[i]+1==expected||arr[i]-1==expected){
                    cnt++;
                } else {
                    cnt = 1e18;
                    break;
                }
            }
            ans=min(ans,cnt);
        }
    }
    if(ans==1e18){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}
