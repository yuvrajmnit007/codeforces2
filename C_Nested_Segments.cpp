#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first.first;
        cin>>a[i].first.second;
        a[i].second=i+1;
    }
    sort(a.begin(),a.end(),[](pair<pair<int,int>,int> &p1,pair<pair<int,int>,int> &p2){
        if(p1.first.first==p2.first.first){
            return p1.first.second>p2.first.second;
        }
        return p1.first.first<p2.first.first;
    });
    int s=a[0].first.first;
    int e=a[0].first.second;
    int idx=a[0].second;
    for(int i=1;i<n;i++){
        if(a[i].first.first>=s && a[i].first.second<=e){
            cout<<a[i].second<<" "<<idx<<endl;
            return 0;
        }
        if(a[i].first.first>=s && a[i].first.second>=e){
            s=a[i].first.first;
            e=a[i].first.second;
            idx=a[i].second;
        }
    
    }
    cout<<-1<<" "<<-1<<endl;
    return 0;
}