class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        for(int i=0;i<pow(2,nums.size());i++){
            vector<int> arr;
            int oneBits=i;
            int t=0;
            while(oneBits){
                if(oneBits&1)
                arr.push_back(nums[t]);
                oneBits >>=1;
                t++;
            }
            subsets.push_back(arr);
        }
        return subsets;
    }
};