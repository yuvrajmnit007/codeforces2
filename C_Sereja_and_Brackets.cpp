#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
class Node {
    public:
    int open,close,matched;
    Node(){
        this->open=0;
        this->close=0;
        this->matched=0;
    }
    Node(int open,int close,int matched){
        this->open=open;
        this->close=close;
        this->matched=matched;
    }
};
vector<Node>segtree;
Node merge(Node left, Node right) {
    int x=min(left.open,right.close);
    Node res;
    res.matched=left.matched+right.matched+x;
    res.open=left.open+right.open-x;
    res.close=left.close+right.close-x;
    return res;
}
void build(int idx, int l, int r) {
    if(l==r){
        if(s[l]=='(')
            segtree[idx]=Node(1,0,0);
        else
            segtree[idx]=Node(0,1,0);
        return;
    }
    int mid=(l+r)/2;
    build(2*idx+1,l,mid);
    build(2*idx+2,mid+1,r);
    segtree[idx]=merge(segtree[2*idx+1],segtree[2*idx+2]);
}
Node query(int start,int end,int idx,int l,int r){
    if(start>r||end<l)
        return Node();
    if(l>=start&&r<=end)
        return segtree[idx];
    int mid=(l+r)/2;
    Node left=query(start,end,2*idx+1,l,mid);
    Node right=query(start,end,2*idx+2,mid+1,r);
    return merge(left, right);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    int n=s.size();
    segtree.resize(4*n);
    build(0,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        Node ans=query(l,r,0,0,n-1);
        cout<<2*ans.matched<<endl;
    }
    return 0;
}