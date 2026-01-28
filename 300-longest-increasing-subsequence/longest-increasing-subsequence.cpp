class Solution {
    int dp[2500];
public:
    int solve(vector<int> &nums,int index){
        if(dp[index]!=-1)
            return dp[index];
        int maxi = 1;
        for(int i=0;i<index;i++){
            if(nums[i]<nums[index]){
                maxi = max(maxi,1+solve(nums,i));
            }
        }
        return dp[index] = maxi;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans = -100;
        for(int i=0;i<nums.size();i++){
            ans = max(ans,solve(nums,i));
        }
        return ans;
    }
};