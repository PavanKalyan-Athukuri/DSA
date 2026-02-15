class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int> bulbCount;
        
        set<int> temp;
        for(int i=0;i<bulbs.size();i++){
            bulbCount[bulbs[i]] += 1;
        }
        for(int i=0;i<bulbs.size();i++){
            if(bulbCount[bulbs[i]]%2){
                temp.insert(bulbs[i]);
            }
        }
        vector<int> res(temp.begin(),temp.end());
        sort(res.begin(),res.end());
        return res;
    }
};