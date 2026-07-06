#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<char,vector<char>>adj;
stack<char>st;
bool possible=1;
void dfs(char node ,vector<int>&vis){
    vis[node-'a']=1;
    for(auto it:adj[node]){
        if(vis[it-'a']==0){
            dfs(it,vis);
        }else if(vis[it-'a']==1){
            possible=0;
        }
    }
    vis[node-'a']=2;
    st.push(node);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string>vec;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        vec.push_back(s);
    }
    for(int i=1;i<n;i++){
        bool flag=1;
        for(int j=0;j<min((int)vec[i].size(),(int)vec[i-1].size());j++){
            if(vec[i-1][j]!=vec[i][j]&&flag){
                adj[vec[i-1][j]].push_back(vec[i][j]);
                flag=0;
                break;
            }
        }
        if(flag&&vec[i-1].size()>vec[i].size()){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    vector<int>vis(26,0);
    for(char u='z';u>='a';u--){
        if(vis[u-'a']==0){
            dfs(u,vis);
        }
    }
    if(!possible){
        cout<<"Impossible"<<endl;
        return 0;
    }
    string ans="";
    while(!st.empty()){
        ans+=(st.top());
        st.pop();
    }
    cout<<ans<<endl;
    return 0;
}
