class Solution {
public:
    int help(vector<int>& rewardValues,int i,int x,vector<vector<int>>&dp){
        if(i>=rewardValues.size())
            return x;
        if(dp[i][x]!=-1)
            return dp[i][x];
        int notTake = help(rewardValues,i+1,x,dp);
        int take = -100000;
        if(x<rewardValues[i])
        take = help(rewardValues,i+1,x+rewardValues[i],dp);
        dp[i][x] = max(take,notTake);
        return dp[i][x];
    }
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        int res = 0;
        vector<vector<int>>dp(rewardValues.size(),vector<int>(4001,-1));
        return help(rewardValues,0,0,dp);
    }
};