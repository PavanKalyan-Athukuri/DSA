class Solution {
    int dp[2500];
public:
    int solve(vector<int>& nums,int index){
        if(dp[index]!=-1)
            return dp[index];
        int ans = 1;
        for(int i=0;i<index;i++){
            if(nums[i]<nums[index]){
                ans = max(ans,1+solve(nums,i));
            }
        }
        return dp[index] = ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = -1e9;
        //int* dp = new int[nums.size()];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<nums.size();i++){
            res = max(res,solve(nums,i));
        }
        return res;
    }
};