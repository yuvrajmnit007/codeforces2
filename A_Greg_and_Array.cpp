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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<pair<pair<int,int>,int>>vec;
        int l=m;
        while(l--){
            int a,b,c;
            cin>>a>>b>>c;
            vec.push_back({{a,b},c});
        }
        vector<int>temp(m,0);
        while(k--){
            int a,b;
            cin>>a>>b;
            a--;
            temp[a]++;
            if(b<m)temp[b]--;
        }
        for(int i=1;i<m;i++){
            temp[i]+=temp[i-1];
        }
        vector<int>ans(n,0);
        int i=0;
        for(auto it:vec){
            int a=it.first.first;
            int b=it.first.second;
            int c=it.second;
            c*=temp[i];
            i++;
            a--;
            ans[a]+=c;
            if(b<n){
                ans[b]-=c;
            }
        }
        for(int i=1;i<n;i++){
            ans[i]+=ans[i-1];
        }
        for(int i=0;i<n;i++){
            ans[i]+=arr[i];
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}