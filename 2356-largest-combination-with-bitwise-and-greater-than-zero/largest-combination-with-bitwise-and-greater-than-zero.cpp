class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int num[32];
        int size = sizeof(num) / sizeof(num[0]);
        for(int i=0;i<candidates.size();i++){
            process(num,candidates[i]);
        }
        return *max_element(num,num+size);
    }
    private:
    void process(int *num,int element){
        int index = 0;
        while(element){
            num[index] += element%2;
            element = element>>1;
            index++;
        }
    }
};