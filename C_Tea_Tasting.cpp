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
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        vector<int>pre(n,0);
        pre[0]=b[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+b[i];
        }
        vector<int>ans(n,0),vec(n,0);
        for(int i=0;i<n;i++){
            int val=a[i];
            if(i>0){
                val+=pre[i-1];
            }
            auto it=lower_bound(pre.begin(),pre.end(),val)-pre.begin();
            if(it>=n||pre[it]>val){
                it--;
            }
            if(it==-1){
                ans[0]+=(val);
                continue;
            }else{
                vec[i]++;
                if(it+1<n)vec[it+1]--;
                if(it+1<n){
                    ans[it+1]+=(val-pre[it]);
                }
            }
        }
        for(int i=1;i<n;i++){
            vec[i]+=vec[i-1];
        }
        for(int i=0;i<n;i++){
            ans[i]+=vec[i]*b[i];
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}