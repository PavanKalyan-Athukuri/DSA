class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i] = -nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            cout << nums[i] <<" ";
        }
        cout <<"\n";
        int size = nums.size();
        long long positive=0;
        long long negative=0;
        for(int i=0;i<size/2;i++){
            negative = negative+(nums[i]*nums[i]);
        }
        cout << negative <<" ";
        for(int j=size/2;j<size;j++){
            positive = positive+(nums[j]*nums[j]);
        }
        long long res = positive-negative;
        return res;
    }
};