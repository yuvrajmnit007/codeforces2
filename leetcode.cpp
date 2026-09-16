class Solution {
public:
    map<int,int>dp;
    vector<vector<int>>nums;
    void palindrome(string s, vector<vector<int>> &nums){
        int n=s.size();
        for(int i=1;i<=n;i++){   // i=j-i+1 => j=i+i-1;
            for(int j=0;j+i-1<n;j++){
                int k = i+j-1;
                if(s[j]==s[k] && ( i<=2 || nums[j+1][k-1])) nums[j][k]=1;
            }
        }
    }
    int f(string &s, int k, int idx){
        if(idx>=s.size()) return 0;
        if(dp.count(idx)) return dp[idx];
        int take=0;
        for(int i=idx;i<s.size();i++){
           if(i-idx+1>=k&&nums[idx][i]){
            take=max(take,1+f(s,k,i+1));
           }

        }
        int nottake=f(s,k,idx+1);
        return dp[idx]=max(take,nottake);
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        nums.resize(n,vector<int>(n,0));
        palindrome(s,nums);       
        memset(dp,-1,sizeof(dp));
        return f(s,k,0);
    }
};