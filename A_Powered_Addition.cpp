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
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int time=0,val=0,mx=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]){
                mx=arr[i];
                continue;
            }
            if(arr[i-1]>arr[i]){
                if(arr[i-1]-arr[i]<=val){
                    arr[i]=mx;
                    continue;
                }else{
                    while(arr[i-1]-arr[i]>val&&time<60){
                        time++;
                        val+=pow(2,time-1);
                    }
                    arr[i]=mx;
                }
            }
        }
        cout<<time<<endl;
    }
    return 0;
}