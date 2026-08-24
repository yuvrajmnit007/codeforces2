#include <iostream>
using namespace std;
const int MOD=676767677;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        
        int d[n+1]={0};
        for(int i=2;i<=n;i++)
            d[i]=a[i]-a[i-1]+1;
        
        int ans=0;
        for(int start=0;start<=1;start++) {
            int x[n+1];
            x[1]=start;
            bool ok=true;
            
            for(int i=2;i<=n;i++) {
                x[i]=d[i]-x[i-1];
                if(x[i]<0||x[i]>1) {
                    ok=false;
                    break;
                }
            }
            if(!ok) continue;
            int sum=0;
            for(int i=1;i<=n;i++)
                sum+=x[i];
            
            if(a[1]==x[1]+n-sum && a[n]==sum+(1-x[n]))
                ans++;
        }
        cout<<ans%MOD<<"\n";
    }
    
    return 0;
}
