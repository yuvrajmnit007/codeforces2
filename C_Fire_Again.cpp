#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<int,int>>q;
    for(int i=0;i<k;i++){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        q.push({l,r});
        vis[l][r]=1;
    }
    pair<int,int>ans;
    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,-1,0,1};
    while(!q.empty()){
        auto [i,j]=q.front();
        q.pop();
        ans={i,j};
        for(int t=0;t<4;t++){
            int x=dx[t]+i,y=dy[t]+j;
            if(x>=0&&x<n&&y>=0&&y<m&&vis[x][y]==0){
                vis[x][y]=1;
                q.push({x,y});
            }
        }
    }
    cout<<ans.first+1<<" "<<ans.second+1<<endl;
    return 0;
}