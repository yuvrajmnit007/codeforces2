#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>>vec(9,vector<int>(9));
        for(int i=0;i<9;i++){
            string s;
            cin>>s;
            for(int j=0;j<9;j++){
                vec[i][j]=s[j]-'0';
            }
        }
        vector<pair<int,int>>temp;
        temp={{0,0},{1,3},{2,6},{3,1},{4,4},{5,7},{6,2},{7,5},{8,8}};
        for(int i=0;i<9;i++){
            int x=temp[i].first,y=temp[i].second;
            if(vec[x][y]==9){
                vec[x][y]=1;
            }else{
                vec[x][y]++;
            }
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<vec[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}