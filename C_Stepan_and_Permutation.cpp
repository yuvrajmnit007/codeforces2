#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>parent,Rank;
int find(int node){
    if(node==parent[node])return node;
    return parent[node]=find(parent[node]);
}
void Union(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent==y_parent){
        return;
    }
    if(Rank[x_parent]>Rank[y_parent]){
        parent[y_parent]=x_parent;
    }else if(Rank[y_parent]>Rank[x_parent]){
        parent[x_parent]=y_parent;
    }else{
        parent[x_parent]=y_parent;
        Rank[y_parent]++;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,a,b;
        cin>>n>>a>>b;
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        parent.resize(n+1);
        Rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        for(int i=1;i+a<=n;i++){
            Union(i,i+a);
        }
        for(int i=1;i+b<=n;i++){
            Union(i,i+b);
        }
        bool ans=true;
        for(int i=1;i<=n;i++){
            if(find(i)!=find(arr[i])){
                ans=false;
                break;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}