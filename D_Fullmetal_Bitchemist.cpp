#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin>>n>>s;
        vector<int>vec={1,0,0};
        int bad=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=(s[i]=='0')?1:-1;
            int a=((sum%3)+3)%3;
            bad+=vec[a];
            vec[a]++;
        }
        int i=0;
        while(i<n){
            int j=i;
            while(j+1<n&&s[j]!=s[j+1])j++;
            int l=j-i+1;
            int m=(l-1)/2;
            bad+=m*(l-m-1);
            i=j+1;
        }
        int total=n*(n+1)/2;
        cout<<total-bad<<endl;
    }
    return 0;
}