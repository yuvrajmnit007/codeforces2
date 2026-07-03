#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int>dx={-1,0,1,0};
vector<int>dy={0,1,0,-1};
bool dfs(vector<vector<char>>&vec,vector<vector<int>>&vis,int pi,int pj,int i,int j,char c){
    for(int p=0;p<4;p++){
        int x=i+dx[p];
        int y=j+dy[p];
        if(x>=0&&x<n&&y>=0&&y<m&&vec[x][y]==c){
            if(!vis[x][y]){
                vis[x][y]=1;
                if(dfs(vec,vis,i,j,x,y,c))return true;
            }else if(!(x==pi&&y==pj)){
                return true;
            }
        }
    }
    return false;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    vector<vector<char>>vec(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0){
                vis[i][j]=1;
                if(dfs(vec,vis,-1,-1,i,j,vec[i][j])){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}