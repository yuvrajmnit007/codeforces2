#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,vector<int>>adj;
bool bfs(int i,vector<int>&color){
    queue<int>q;
    q.push(i);
    color[i]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto j:adj[node]){
            if(color[j]==0){
                color[j]=-color[node];
                q.push(j);
            }else{
                if(color[j]==color[node]&&j!=node){
                    return false;
                }
            }
        }
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>color(n+1,0);
    bool ans=true;
    for(int i=0;i<=n;i++){
        if(color[i]==0&&!adj[i].empty()){
            if(!bfs(i,color)){
                ans=0;
                break;
            }
        }
    }
    if(ans==0){
        cout<<0<<endl;
        return 0;
    }
    int cnt1=0,cnt2=0;
    for(auto it:color){
        if(it==-1)cnt1++;
        if(it==1)cnt2++;
    }
    cout<<cnt1*cnt2-n+1<<endl;
    return 0;
}