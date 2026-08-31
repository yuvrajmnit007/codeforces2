#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,m;
    cin>>a>>m;
    for(int i=0;i<m;i++){
        a=(a+a%m);
    }
    if(a%m==0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}