#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin>>n;
        unordered_map<int,int>mp;
        int sum=0;
        bool ok=false;
        mp[sum]++;

        for(int i=0;i<n;i++){

            int temp;
            cin>>temp;

            if(i%2==0) sum+=temp;
            else sum-=temp;

            if(mp.find(sum)!=mp.end()){
                ok=true;
                break;
            }
            mp[sum]++;
        }
        if(!ok) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}