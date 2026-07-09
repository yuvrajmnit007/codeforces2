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
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    parent.resize(26);
    Rank.resize(26,0);
    vector<int>present(26,0);
    for(int i=0;i<26;i++){
        parent[i]=i;
    }
    for(int i=0;i<n;i++){
        Union(s1[i]-'a',s2[i]-'a');
    }
    int ans=0;
    vector<pair<int,int>>vec;
    for(int i=0;i<26;i++){
        if(parent[i]!=i){
            ans++;
            vec.push_back({i,parent[i]});
        }
    }
    cout<<ans<<endl;
    for(auto it:vec){
        char p='a'+it.first;
        char q='a'+it.second;
        cout<<p<<" "<<q<<endl;
    }
    return 0;
}