class Solution {
public:
    long long helper(vector<int>& nums,int index,long long dp[100001][2],int pos)
    {
        if(index==nums.size())
            return 0;
        if(dp[index][pos]!=-1)
            return dp[index][pos];
        if(pos)
       return dp[index][pos] = max(1ll*nums[index]+helper(nums,index+1,dp,!pos),(1ll*nums[index]+helper(nums,index+1,dp,pos)));
        else
        return dp[index][pos] = (-1ll*nums[index]+helper(nums,index+1,dp,!pos));
    }
public:
    long long maximumTotalCost(vector<int>& nums) {
        long long dp[100001][2];
        memset(dp,-1,sizeof(dp));
        return helper(nums,0,dp,1);
    }
};