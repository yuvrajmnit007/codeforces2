#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int>arr(n),arr1(m);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int j=0;j<m;j++){
        cin>>arr1[j];
    }
    vector<int>pre(n);
    pre[0]=arr[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+arr[i];
    }
    for(int i=0;i<m;i++){
        auto it=lower_bound(pre.begin(),pre.end(),arr1[i])-pre.begin();
        if(pre[it]==arr1[i]){
            cout<<it+1<<" "<<arr[it]<<endl;
        }else{
            if(it!=0)cout<<it+1<<" "<<arr1[i]-pre[it-1]<<endl;
            else cout<<1<<" "<<arr1[i]<<endl;
        }
    }
    return 0;
}