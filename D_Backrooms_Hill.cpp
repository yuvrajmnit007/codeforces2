#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(vector<int>&vec){
    int i=1;
    while(i<vec.size()&&vec[i]>vec[i-1]){
        i++;
    }
    if(i==vec.size())return false;
    while(i<vec.size()&&vec[i]<vec[i-1]){
        i++;
    }
    if(i==vec.size())return true;
    return false;
}
vector<int>merge(vector<int>&a,vector<int>&b){
    vector<int>ans;
    int i=0,j=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]<b[j]){
            ans.push_back(a[i]);
            i++;
        }else{
            ans.push_back(b[j]);
            j++;
        }
    }
    while(i<a.size()){
        ans.push_back(a[i]);
        i++;
    }
    while(j<b.size()){
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>odd,even;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(i%2){
                odd.push_back(x);
            }else{
                even.push_back(x);
            }
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        vector<int>oddm,evenm;
        int i=0;
        for(i=0;i<odd.size();i+=2){
            oddm.push_back(odd[i]);
        }
        int j;
        if((odd.size()-1)%2==0){
            j=odd.size()-2;
        }else{
            j=odd.size()-1;
        }
        for(;j>=0;j-=2){
            oddm.push_back(odd[j]);
        }
        i=0;
        for(i=0;i<even.size();i+=2){
            evenm.push_back(even[i]);
        }
        if((even.size()-1)%2==0){
            j=even.size()-2;
        }else{
            j=even.size()-1;
        }
        for(;j>=0;j-=2){
            evenm.push_back(even[j]);
        }
        vector<int>vec1,vec2;
        vec1=merge(oddm,evenm);
        vec2=merge(evenm,oddm);
        if(check(vec1)||check(vec2)){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}