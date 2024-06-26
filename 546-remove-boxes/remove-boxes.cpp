class Solution {
public:
    vector<vector<vector<int>>> dp;
    int helper(vector<int>& boxes,int l, int r,int streak){
        if(l>r)
            return 0;
                if(l==r)return (streak+1)*(streak+1);
        if(dp[l][r][streak]!=-1)
            return dp[l][r][streak];
        int ans = (streak+1)*(streak+1)+helper(boxes,l+1,r,0);
        for(int i=l+1;i<=r;i++){
            if(boxes[i]==boxes[l])
                ans = max(ans,helper(boxes,l+1,i-1,0)+helper(boxes,i,r,streak+1));
        }
        dp[l][r][streak] = ans;
        return ans;
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        dp = vector<vector<vector<int>>> (n, vector<vector<int>>(n, vector<int>(n+1, -1)));
        return helper(boxes,0,n-1,0);
    }
};