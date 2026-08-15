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
vector<int>lazy;
void build(int idx,int l,int r,vector<int>&arr){
    if(l==r){
        segtree[idx]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*idx+1,l,mid,arr);   
    build(2*idx+2,mid+1,r,arr);
    segtree[idx]=(segtree[2*idx+1]+segtree[2*idx+2]);
}
void update(int idx,int l,int r,int ql,int qr,int x){
    if(lazy[idx]!=0){
        segtree[idx]=segtree[idx]^((r-l+1)%2==0?0:lazy[idx]);
        if(l!=r){
            lazy[2*idx+1]^=lazy[idx];
            lazy[2*idx+2]^=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(ql>r||qr<l)return;
    if(ql<=l&&r<=qr){
        segtree[idx]=segtree[idx]^((r-l+1)%2==0?0:x);
        if(l!=r){
            lazy[2*idx+1]^=x;
            lazy[2*idx+2]^=x;   
        }
        return;
    }
    int mid=(l+r)/2;
    update(2*idx+1,l,mid,ql,qr,x);
    update(2*idx+2,mid+1,r,ql,qr,x);
    segtree[idx]=(segtree[2*idx+1]+segtree[2*idx+2]);
}
int query(int idx,int l,int r,int ql,int qr){
    if(lazy[idx]!=0){
        segtree[idx]=segtree[idx]^((r-l+1)%2==0?0:lazy[idx]);
        if(l!=r){
            lazy[2*idx+1]^=lazy[idx];
            lazy[2*idx+2]^=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(ql>r||qr<l)return 0;
    if(ql<=l&&r<=qr)return segtree[idx];
    int mid=(l+r)/2;
    int left=query(2*idx+1,l,mid,ql,qr);
    int right=query(2*idx+2,mid+1,r,ql,qr);
    return (left+right);
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
    lazy.resize(4*n);
    build(0,0,n-1,arr);
    int q;
    cin>>q;
    while(q--){
        int a;
        cin>>a;
        if(a==1){
            int l,r;
            cin>>l>>r;
            l--;r--;
            cout<<query(0,0,n-1,l,r)<<endl;
        }else{
            int l,r,x;
            cin>>l>>r>>x;
            l--;r--;
            update(0,0,n-1,l,r,x);
        }
    }
    return 0;
}