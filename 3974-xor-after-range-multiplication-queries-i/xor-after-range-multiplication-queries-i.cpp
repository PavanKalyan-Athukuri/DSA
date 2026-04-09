class Solution {
public:
    long long int mod = 1000000007;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int i=0;
        while(i<queries.size()){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];
            int j = l;
            while(j<=r){
                long long int temp = nums[j];
                long long int res = ((temp%mod)*(v)%mod)%mod;
                nums[j] = (int) res;
                j += k;
            }
            i++;
        }
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            res = res^nums[i];
        }
        return res;
    }
};