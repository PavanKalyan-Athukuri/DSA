class Solution {
public:
    string makeDigit(int num, int digits) {
        string num_str = to_string(num);
        if (num_str.size() < digits) {
            num_str = string(digits - num_str.size(), '0') + num_str;
        }
        return num_str;
    }
    
    unordered_set<string> makeSwapChanges(string num, int digits) {
        unordered_set<string> possible_strings;
        possible_strings.insert(num); // never swap // 1
 
        for(int i = 0; i < digits; ++i) { // 7
            for(int j = i + 1; j < digits; ++j) { // 7
                if(num[i] != num[j]) {
                    swap(num[i], num[j]); // swapping one time
                    possible_strings.insert(num); // 1
                    swap(num[i], num[j]); // swapping again to reverse the effects
                }
            }
        } // 50
        return possible_strings;
    }
    
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for(auto it:nums) 
            mx = max(it,mx);
 
        int digits = to_string(mx).size();
        vector<string> arr;
        for(auto it: nums)
            arr.push_back(makeDigit(it,digits));
 
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                unordered_set<string> possible_strings = makeSwapChanges(arr[j],digits);
                for(auto s:possible_strings){
                    if(s==arr[i])
                        ans++;
                }
            }
        }
        return ans;
    }
};