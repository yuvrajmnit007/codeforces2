#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int row;
    int col;
    string str;
    int dist;
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<char>>vec(n,vector<char>(m));
    int sr,sc,er,ec;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
            if(vec[i][j]=='A'){
                sr=i;
                sc=j;
            }
            if(vec[i][j]=='B'){
                er=i;
                ec=j;
            }
        }
    }
    queue<node>q;
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<int>dr={0,1,0,-1};
    vector<int>dc={-1,0,1,0};
    vector<char>dirc={'L','D','R','U'};
    q.push({sr,sc,"",0});
    vis[sr][sc]=1;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        if(vec[it.row][it.col]=='B'){
            cout<<"YES"<<endl;
            cout<<it.dist<<endl;
            cout<<it.str<<endl;
            return 0;
        }
        for(int i=0;i<4;i++){
            int nr=it.row+dr[i];
            int nc=it.col+dc[i];
            if(nr<n&&nr>=0&&nc<m&&nc>=0&&vec[nr][nc]!='#'&&!vis[nr][nc]){
                vis[nr][nc]=1;
                node p;
                p.str=it.str;
                p.str.push_back(dirc[i]);
                p.dist=it.dist+1;
                p.row=nr;
                p.col=nc;
                q.push(p);
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}