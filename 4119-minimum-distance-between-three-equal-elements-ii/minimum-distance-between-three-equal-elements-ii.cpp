class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>> same_elements_map;
        for(int i=0;i<nums.size();i++){
            same_elements_map[nums[i]].push_back(i);
        }
        int ans = -1;
        int ans1 = 100000000;
        for(auto const& pair:same_elements_map){
            vector<int> vec = pair.second;
            int index = pair.first;
            if(vec.size()<3)
                continue;
            sort(vec.begin(),vec.end());
            int n = vec.size();
            int i=0;
            int j=1;
            int k=2;
            ans = abs(vec[i]-vec[j])+abs(vec[j]-vec[k])+abs(vec[k]-vec[i]);
            ans = min(ans,ans1);
            int temp = abs(vec[i]-vec[j])+abs(vec[k]-vec[i]);
            while(k<n){
                ans1 = ans;     
                ans = abs(vec[i]-vec[j])+abs(vec[j]-vec[k])+abs(vec[k]-vec[i]);
                ans = min(ans1,ans);
                i=j;
                j=k;
                k++;
            }
            ans1 = ans;
        }
        return ans;
    }
};