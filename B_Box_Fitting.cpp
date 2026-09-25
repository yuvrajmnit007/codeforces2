#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,w;
		cin>>n>>w;
        vector<int>a(n);
		for(int i=0;i<n;i++){
            cin>>a[i];
        }
		vector<int>cnt(32,0);
		for(int i=0;i<n;i++){
            cnt[log2(a[i])]++;
        }
		int ans=0;
		int used=0; 
		while(used<n){
			int temp=w; 
			for(int i=31;i>=0;i--){ 
				while(cnt[i]>0&&(1<<i)<=temp){ 
					temp-=(1<<i);
					cnt[i]--;
					used++;
				}
			}
			ans++; 
		}
		cout<<ans<<"\n";
    }
    return 0;
}