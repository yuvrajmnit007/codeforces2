#include <bits/stdc++.h>
using namespace std;
#define int long long
// vector<int>segtree;
// vector<int>lazy;
// void build(int node,int start,int end,vector<int>&arr){
//     if(start==end){
//         segtree[node]=arr[start];
//     }else{
//         int mid=(start+end)/2;
//         build(2*node,start,mid,arr);
//         build(2*node+1,mid+1,end,arr);
//         segtree[node]=(segtree[2*node]+segtree[2*node+1]);
//     }
// }
// void update(int node,int start,int end,int l,int r,int val){
//     if(lazy[node]!=1){
//         segtree[node]*=lazy[node];
//         if(start!=end){
//             lazy[2*node]*=lazy[node];
//             lazy[2*node+1]*=lazy[node];
//         }
//         lazy[node]=-1;
//     }
//     if(start>end||start>r||end<l)return;
//     if(start>=l&&end<=r){
//         segtree[node]*=val;
//         if(start!=end){
//             lazy[2*node]*=val;
//             lazy[2*node+1]*=val;
//         }
//         return;
//     }
//     int mid=(start+end)/2;
//     update(2*node,start,mid,l,r,val);
//     update(2*node+1,mid+1,end,l,r,val);
//     segtree[node]=(segtree[2*node]+segtree[2*node+1]);
// }
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<int>a(n+1);
        vector<int>b(m);
        // segtree.clear();
        // lazy.clear();
        // segtree.resize(4*n+1);
        // lazy.resize(4*n+1,1);
        vector<int>pre(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pre[i]=pre[i-1]+a[i];
        }
        // build(1,1,n,a);
        for(int i=0;i<m;i++){
            cin>>b[i];
            // update(1,1,n,1,b[i],-1);
            // ans=max(ans,segtree[1]);
        }
        sort(b.rbegin(),b.rend());
        int mx=-1e18;
        int ans=0;
        for(auto it:b){
            int mx1=mx;
            mx=max(mx,ans-pre[it]);
            ans=max(ans,pre[it]+mx1);
        }
        cout<<pre[n]+2*max(ans,mx)<<endl;
    }
    return 0;
}