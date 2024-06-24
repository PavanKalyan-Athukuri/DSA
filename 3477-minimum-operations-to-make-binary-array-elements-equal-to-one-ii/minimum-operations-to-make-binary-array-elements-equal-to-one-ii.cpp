class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int flip = 0;
        for(int i=0;i<nums.size();i++){
            if((!nums[i]&&!(flip%2))||(nums[i]&&flip%2)){
                flip++;
                count++;
            }
        }
        // if(!nums[nums.size()-2]||!nums[nums.size()-1])
        //     return -1;
        return count;
    }
};