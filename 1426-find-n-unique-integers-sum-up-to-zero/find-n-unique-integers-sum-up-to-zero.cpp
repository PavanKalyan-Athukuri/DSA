class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int mid = n/2;
        int element = -mid;
        int positive = mid;
        for(int i=0;i<mid;i++){
            res.push_back(element);
            element++;
            res.push_back(positive);
            positive--;
        }
        if(n%2)
        res.push_back(0);
        return res;
    }
};