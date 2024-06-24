class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size()-2;i++){
            if(!nums[i]){
                for(int j=i;j<=i+2;j++){
                    nums[j] = !nums[j];
                }
                count++;
            }
        }
        if(!nums[nums.size()-2]||!nums[nums.size()-1])
            return -1;
        return count;
    }
};