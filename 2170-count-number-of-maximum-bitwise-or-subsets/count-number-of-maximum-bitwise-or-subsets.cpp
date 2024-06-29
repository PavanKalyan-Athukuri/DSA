class Solution {
public:

    int dp[16][1000001];

    int f(int index, int currOr, vector<int>& nums, int maxOr){
        if(index >= nums.size()){
            return currOr == maxOr;
        }
        if(dp[index][currOr] != -1) return dp[index][currOr];
        int ans = f(index + 1, currOr, nums, maxOr);
        ans += f(index + 1, currOr | nums[index], nums, maxOr);
        return dp[index][currOr] = ans;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        int maxOr = 0;
        for(auto&i:nums){
            maxOr |= i;
        }
        return f(0, 0, nums, maxOr);
    }
};