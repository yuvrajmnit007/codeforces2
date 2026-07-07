#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<int>>grid;
vector<vector<int>>vis;
vector<int>dx={-1,0,1,0};
vector<int>dy={0,1,0,-1};
int bfs(int i,int j){
    int ans=0;
    queue<pair<int,int>>q;
    vis[i][j]=1;
    q.push({i,j});
    while(!q.empty()){
        pair<int,int>p=q.front();
        int a=p.first;
        int b=p.second;
        q.pop();
        ans+=grid[a][b];
        for(int r=0;r<4;r++){
            int x=a+dx[r];
            int y=b+dy[r];
            if(x>=0&&x<n&&y>=0&&y<m&&vis[x][y]==0&&grid[x][y]!=0){
                vis[x][y]=1;
                q.push({x,y});
            }
        }
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin>>n>>m;
        grid.assign(n,vector<int>(m));
        vis.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]!=0){
                    ans=max(ans,bfs(i,j));
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}