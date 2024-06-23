class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        vector<double> res;
        while(i<j){
            double ans = ((double)nums[i]+(double)nums[j])/2;
            res.push_back(ans);
            i++;
            j--;
        }
        double small = 100;
        for(int i=0;i<res.size();i++){
            small = min(small,res[i]);
        }
        return small;
    }
};