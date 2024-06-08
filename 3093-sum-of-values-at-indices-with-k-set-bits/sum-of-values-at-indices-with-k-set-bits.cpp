class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int res = 0;
        for(int i=0;i<nums.size();i++){
            int count = __builtin_popcount(i);
            if(k==count)
                res = res+nums[i];
        }
        return res;
    }
};