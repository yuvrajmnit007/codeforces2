#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int mx=0,mn=0;
        stack<int>st;
        vector<int>pme(n),nme(n),pse(n),nse(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                pme[i]=-1;
            }else{
                pme[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }else{
                pse[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.empty()){
                nme[i]=n;
            }else{
                nme[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }else{
                nse[i]=st.top();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            mx+=(i-pme[i])*(nme[i]-i)*arr[i];
            mn+=(i-pse[i])*(nse[i]-i)*arr[i];
        }
        cout<<mx-mn<<endl;
    }
    return 0;
}