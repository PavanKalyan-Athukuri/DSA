class Solution {
    struct FirstOnlyCompare{
        bool operator()(const pair<int,int> lhs,const pair<int,int> rhs) const{
            return lhs.first<rhs.first;
        }
    };
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<pair<int,int>,int, FirstOnlyCompare> indexmap;
        for(int i=0;i<nums.size();i++){
                indexmap[{nums[i],i}] += 1;
        }
        map<int,vector<pair<int,int>>> resmap;
        for (const auto& [key, value] : indexmap) {
            resmap[value].push_back(key);
        }
        for(const auto& [key,value]: resmap){
            cout << key << " key ";
            cout << value.size() <<" value.size()\n";
            //cout << value.second << " value.second\n"; 
        }
        vector<int> res;
        for(const auto& [key,value]: resmap){
            if(resmap[key].size()==1){
                res.push_back(value[0].second);
            }
        }
        if(res.size()==0)
        return -1;
        sort(res.begin(),res.end());
        return nums[res[0]];

    }
};