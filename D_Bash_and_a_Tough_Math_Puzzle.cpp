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
vector<int>segtree;
void build(int idx,int l,int r,vector<int>&arr){
    if(l==r){
        segtree[idx]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*idx+1,l,mid,arr);   
    build(2*idx+2,mid+1,r,arr);
    segtree[idx]=__gcd(segtree[2*idx+1],segtree[2*idx+2]);
}
void update(int idx,int l,int r,int pos,int val){
    if(l==r){
        segtree[idx]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid){
        update(2*idx+1,l,mid,pos,val);
    }else{
        update(2*idx+2,mid+1,r,pos,val);
    }
    segtree[idx]=__gcd(segtree[2*idx+1],segtree[2*idx+2]);
}
void query(int idx,int l,int r,int ql,int qr,int x,int &count){
    if(ql>r||qr<l||count>1)return;
    if(ql<=l&&r<=qr){
        if(segtree[idx]%x==0)return;
        if(l==r){
            count++;
            return;
        }
    }
    int mid=(l+r)/2;
    query(2*idx+1,l,mid,ql,qr,x,count);
    query(2*idx+2,mid+1,r,ql,qr,x,count);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    segtree.resize(4*n);
    build(0,0,n-1,arr);
    int q;
    cin>>q;
    while(q--){
        int a;
        cin>>a;
        if(a==1){
            int l,r,x;
            cin>>l>>r>>x;
            l--;r--;
            if(l==r){
                cout<<"YES"<<endl;
                continue;
            }
            int count=0;
            // cout<<query(0,0,n-1,l,r,x,count)<<endl;
            query(0,0,n-1,l,r,x,count);
            if(count<=1){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            int idx,x;
            cin>>idx>>x;
            idx--;
            update(0,0,n-1,idx,x);
        }
    }
    return 0;
}