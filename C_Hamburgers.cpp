#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while (t--) {
        string st;
        cin>>st;
        int nb,nc,ns;
        cin>>nb>>ns>>nc;
        int pb,ps,pc;
        cin>>pb>>ps>>pc;
        int total;
        cin>>total;
        int fb=0,fc=0,fs=0;
        for(auto it:st){
            if(it=='B')fb++;
            if(it=='C')fc++;
            if(it=='S')fs++;
        }
        int l=0,h=1e13;
        if(fb==0)nb=0;
        if(fc==0)nc=0;
        if(fs==0)ns=0;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            int cost=max(0LL,(mid*fb*pb)-nb*pb)+max(0LL,(mid*fs*ps)-ns*ps)+max(0LL,(mid*fc*pc)-nc*pc);
            if(cost<=total){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}