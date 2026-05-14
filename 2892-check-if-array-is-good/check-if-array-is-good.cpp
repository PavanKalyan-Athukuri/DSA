class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi = nums[nums.size()-1];
        if(nums.size()<=maxi||nums.size()>maxi+1)
            return false;
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-2){
                if(nums[i]!=maxi){
                    return false;
                }
                return true;
            }
            else{
                if(nums[i]!=i+1)
                    return false;
            }
        }
        return true;
    }
};