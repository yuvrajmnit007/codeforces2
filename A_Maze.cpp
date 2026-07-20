#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,1,0,-1};
int n,m,k;
vector<vector<char>> vec;
vector<vector<bool>> vis;
int val;
void dfs(int i,int j){
    if(val==0) return;
    vis[i][j]=1;
    val--;
    for(int d=0;d<4;d++){
        if(val==0) return;
        int ni=i+dx[d];
        int nj=j+dy[d];
        if(ni<0||nj<0||ni>=n||nj>=m) continue;
        if(vec[ni][nj]=='#'||vis[ni][nj]) continue;
        dfs(ni,nj);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    vec.assign(n,vector<char>(m));
    vis.assign(n,vector<bool>(m,false));
    int cnt=0;
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
            if(vec[i][j]=='.'){
                x=i;
                y=j;
                cnt++;
            }
        }
    }
    val=cnt-k;
    dfs(x,y);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vec[i][j]=='#') cout<<'#';
            else if(vis[i][j]) cout<<'.';
            else cout<<'X';
        }
        cout<<endl;
    }
    return 0;
}