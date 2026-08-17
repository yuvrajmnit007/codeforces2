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
double f(double x,vector<double>&arr){
    double sum=0,mx1=0,mx2=0;
    vector<double>temp=arr;
    for(int i=0;i<arr.size();i++){
        temp[i]=temp[i]-x;  
    }
    for(int i=0;i<arr.size();i++){
        if(temp[i]+sum>0){
            sum+=temp[i];
            mx1=max(mx1,sum);
        }else{
            sum=0;
        }
    }
    sum=0;
    for(int i=0;i<arr.size();i++){
        temp[i]=-temp[i];
    }
    for(int i=0;i<arr.size();i++){
        if(temp[i]+sum>0){
            sum+=temp[i];
            mx2=max(mx2,sum);
        }else{
            sum=0;
        }
    }
    return max(mx1,mx2);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<double>arr(n);
    double mx=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mx=max(mx,arr[i]);
    }
    double ans=0,l=-10001.00,h=10001.00;
    int k=100;
    while(k--){
        double m1=l+(h-l)/3.0;
        double m2=h-(h-l)/3.0;
        if(f(m1,arr)>f(m2,arr)){
            l=m1;
        }else{
            h=m2;   
        }
    }
    cout<<fixed<<setprecision(15)<<f((l+h)/2.0,arr)<<endl;
    return 0;
}