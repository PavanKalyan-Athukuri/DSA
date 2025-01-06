// #include<bits/stdc++.h>
// using namespace std;
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ones;
        for(int i=0;i<boxes.length();i++){
            if(boxes[i]=='1'){
                ones.push_back(i);
            }
        }
        vector<int> res;
        int j=0;
        while(j<boxes.length()){
            int i=0;
            int temp = 0;
            while(i<ones.size()){
                temp += abs(ones[i]-j);
                i++;
            }
            res.push_back(temp);
            j++;
        }
        return res;
    }
};