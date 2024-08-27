class Solution {
public:
    int mod = 1e9+7;
    int modpow(long base,int exp){
        long result = 1;
        while(exp){
            if(exp&1){
                result *= base;
                result = result%mod;
            }
            base = base*base;
            base = base%mod;
            exp = exp>>1;
        }
        return result;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier==1)
            return nums;
        int maxi = *max_element(nums.begin(), nums.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(k&& (1LL*multiplier*pq.top().first)<=maxi){
            k--;
            int val = (multiplier*pq.top().first)%mod;
            int ind = pq.top().second;
            pq.pop();
            pq.push({val,ind});
        }
        const long pow = modpow(multiplier,k/n);
        while(!pq.empty()){
            int val = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            if(k%n>0){
                --k;
                nums[ind] = ((1LL * multiplier * pow)%mod * val)%mod;
            }
            else{
                nums[ind] = (1LL * pow * val)%mod;
            }
        }
        return nums;
    }
};