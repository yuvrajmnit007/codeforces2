#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    set<int>st;
    int mx=-1e18;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mx=max(mx,x);
        st.insert(x);
    }
    // set<int>ans;
    // for(auto it:st){
    //     set<int>temp;
    //     int val=it;
    //     if(st.find(val+2)!=st.end()){
    //         temp.insert(val);
    //         temp.insert(val+2);
    //     }
    //     if(st.find(val+4)!=st.end()){
    //         temp.insert(val);
    //         temp.insert(val+4);
    //     }
    //     if(ans.size()<=temp.size()){
    //         ans=temp;
    //     }
    // }
    // if(ans.size()>0){
    //     cout<<ans.size()<<endl;
    //     for(auto it:ans){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }else{
    //     int k=1;
    //     while(k<mx){
    //         for(auto it:st){
    //             if(st.find(it+k)!=st.end()){
    //                 cout<<2<<endl;
    //                 cout<<it<<" "<<it+k<<endl;
    //                 return 0;
    //             }
    //             k*=2;
    //         }
    //     }
    //     cout<<1<<endl;
    //     cout<<mx<<endl;
    // }
    int k=1;
    set<int>ans;
    while(k<=1e10){
        for(auto it:st){
            if((st.find(it+k)!=st.end())&&(st.find(it+2*k)!=st.end())){
                cout<<3<<endl;
                cout<<it<<" "<<it+k<<" "<<it+2*k<<endl;
                return 0;  
            }else if(st.find(it+k)!=st.end()){
                ans.clear();
                ans.insert(it);
                ans.insert(it+k);
            }
        }
        k*=2;
    }
    if(ans.size()==0){
        cout<<1<<endl;
        cout<<mx<<endl;
    }else{
        cout<<2<<endl;
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}