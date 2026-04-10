class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int minDist = 100000;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]==nums[j]&&nums[j]==nums[k]){
                        minDist = min(minDist,(abs(i-j)+abs(j-k)+abs(k-i)));
                    }
                }
            }
        }
        if(minDist==100000)
            return -1;
        return minDist;
    }
};