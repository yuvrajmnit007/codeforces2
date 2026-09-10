#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>prime;
    int temp=n;
    map<int,int>mp;
    for(int i=2;i*i<=temp;i++){
        if(temp%i==0){
            int cnt=0;
            while(temp%i==0){
                cnt++;
                temp/=i;
            }
            prime.push_back(i);
            mp[i]=cnt;
        }
    }
    if(temp>1){
        prime.push_back(temp);
        mp[temp]++;
    }
    int mx=0;
    set<int>st;
    for(auto it:mp){
        st.insert(it.second);
        mx=max(mx,it.second);
    }
    int pdt=1;
    for(auto it:prime){
        pdt*=it;
    }
    cout<<pdt<<" ";
    int cnt=0;
    int val=mx;
    while(mx>1){
        cnt++;
        mx=(mx/2);
    }
    if(pow(2,cnt)<val){
        cnt+=2;
    }else if(st.size()>1)cnt++;
    cout<<cnt<<endl;
    return 0;
}