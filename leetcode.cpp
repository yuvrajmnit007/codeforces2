class Solution {
public:
    long long f(long long k){
        long long ans=k;
        int s=k;
        while(s>=10){
            ans*=10;
            ans+=(s%10);
            s/=10;
        }
        return ans;
    }
    long long minOperations(vector<int>& nums) {
        vector<long long>vec1,vec2;
        for(int i=0;i<=1e5;i++){
            for(int j=0;j<=9;j++){
                long long s=i*10+j;
                long long val=f(s);
                if(val%2==1)vec1.push_back(val);
                if(val%2==1)vec2.push_back(val);
            }
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long mn=2e18; 
            if(nums[i]%2==1) {
                auto a=lower_bound(vec1.begin(),vec1.end(),nums[i])-vec1.begin();
                mn=min({mn,abs(vec1[a+1]-nums[i]),abs(vec1[a]-nums[i]),abs(vec1[a-1]-nums[i])});
            }else{
                auto it=lower_bound(vec2.begin(),vec2.end(),nums[i])-vec2.begin();
                mn=min({mn,abs(vec2[a+1]-nums[i]),abs(vec2[a]-nums[i]),abs(vec2[a-1]-nums[i])});
            }
            ans+=mn;
        }
        return ans;
    }
};