#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while (t--) {
        int n;
        cin>>n;
        vector<pair<int,int>>vec1;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            vec1.push_back({a,1});
            vec1.push_back({b,-1});
        }
        sort(vec1.begin(),vec1.end());
        int sum=0;
        int age=0,k=0;
        for(auto it:vec1){
            sum+=it.second;
            if(sum>k){
                age=it.first;
                k=sum;
            }
        }
        cout<<age<<" "<<k<<endl;
    }
    return 0;
}