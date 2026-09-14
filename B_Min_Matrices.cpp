#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        if(k<n||k>=2*n){
            cout<<-1<<endl;
        }else{
            vector<vector<int>>vec(n,vector<int>(n,0));
            int x=2*n-k;
            int j=1;
            for(int i=0;i<x;i++){
                vec[i][i]=j;
                j++;
            }
            for(int i=0;i<n;i++){
                for(int k=0;k<n;k++){
                    if(vec[i][k]==0){
                        vec[i][k]=j;
                        j++;
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<vec[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}