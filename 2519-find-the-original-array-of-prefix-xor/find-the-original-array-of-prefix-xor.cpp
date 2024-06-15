class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int currentXor=pref[0];
        vector<int> res(pref.size(),-1);
        res[0] = pref[0];
        for(int i=1;i<pref.size();i++){
            res[i] = currentXor^pref[i];
            currentXor = currentXor^res[i];
        }
        return res;
    }
};