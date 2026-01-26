class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int diff = 10000000;
        for(int i=0;i<arr.size()-1;i++){
            diff = min(diff,(arr[i+1]-arr[i]));
        }
        vector<vector<int>> res;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==diff){
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);
                res.push_back(temp);
            }
        }
        return res;
    }
};