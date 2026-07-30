/*
██╗   ██╗██╗   ██╗██╗   ██╗██████╗  █████╗      ██╗
╚██╗ ██╔╝██║   ██║██║   ██║██╔══██╗██╔══██╗     ██║
 ╚████╔╝ ██║   ██║██║   ██║██████╔╝███████║     ██║
  ╚██╔╝  ██║   ██║╚██╗ ██╔╝██╔══██╗██╔══██║██   ██║
   ██║   ╚██████╔╝ ╚████╔╝ ██║  ██║██║  ██║╚█████╔╝
   ╚═╝    ╚═════╝   ╚═══╝  ╚═╝  ╚═╝╚═╝  ╚═╝ ╚════╝
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int val){
    int sum=0;
    int k=val;
    while(k>0){
        sum+=(k%10);
        k/=10;
    }
    return sum;
}
int power(int base,int exp){
    int res=1;
    while(exp){
        if(exp%2){
            res*=base;
        }
        base*=base;
        exp/=2;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    vector<int>ans;
    for(int i=1;i<=81;i++){
        int val=c+b*power(i,a);
        if(f(val)==i&&val<=1e9){
            ans.push_back(val);
        }
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}