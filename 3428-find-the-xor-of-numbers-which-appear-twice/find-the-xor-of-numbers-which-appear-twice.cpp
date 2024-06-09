constexpr int RANGE_LIMIT = 51;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        // support variables
        int res = 0;
        bool seen[RANGE_LIMIT] = {};
        // parsing nums
        for (int n: nums) {
            if (!seen[n]) seen[n] = true;
            else res ^= n;
        }
        return res;
    }
};