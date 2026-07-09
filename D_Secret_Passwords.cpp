#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>parent,Rank;
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
    parent.resize(26);
    Rank.resize(26,0);
    for(int i=0;i<26;i++){
        parent[i]=i;
    }
    vector<string>vec;
    vector<int>present(26,0);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        vec.push_back(s);
        present[s[0]-'a']++;
        for(int j=1;j<s.size();j++){
            present[s[j]-'a']++;
            Union(s[0]-'a',s[j]-'a');
        }
    }
    unordered_set<int>st;
    for(int i=0;i<26;i++){
        if(present[i]>0)st.insert(find(i));
    }
    cout<<(int)st.size()<<endl;
    return 0;
}