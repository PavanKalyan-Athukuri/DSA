class Solution {
public:
    int dp[501][501];
    int helper(string word1,string word2,int i,int j){
        if(i==word1.length())
            return (word2.length()-j);
        if(j==word2.length())
            return (word1.length()-i);
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(word1[i]==word2[j])
            return helper(word1,word2,i+1,j+1);
        int replace = 1+helper(word1,word2,i+1,j+1);
        int remove = 1+helper(word1,word2,i+1,j);
        int insert = 1+helper(word1,word2,i,j+1);
        return dp[i][j] = min({replace,remove,insert});
        
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return helper(word1,word2,0,0);
    }
};