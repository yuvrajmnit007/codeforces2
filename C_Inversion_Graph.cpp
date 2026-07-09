#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>parent;
vector<int>Rank;
int find(int node){
    if(parent[node]==node)return node;
    return parent[node]=find(parent[node]);
}
void Union(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent==y_parent)return;
    if(Rank[x_parent]>Rank[y_parent]){
        parent[y_parent]=x_parent;
    }else if(Rank[x_parent]<Rank[y_parent]){
        parent[x_parent]=y_parent;
    }else{
        parent[x_parent]=y_parent;
        Rank[x_parent]++;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        parent.resize(n+1);
        Rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            // Union(arr[i],i+1);
        }
        // set<int>st;
        // for(int i=1;i<=n;i++){
        //     st.insert(find(i));
        // }
        // cout<<st.size()<<endl;
        int mx=0;
        int ans=0;
        for(int i=0;i<n;i++){
            mx=max(mx,arr[i]);
            if(mx==i+1)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}