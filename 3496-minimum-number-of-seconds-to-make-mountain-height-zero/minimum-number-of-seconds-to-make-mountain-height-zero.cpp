class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1,right = 1e16;
        while(left<right){
            long long mid = left+(right-left)/2;
            if(helper(mid,mountainHeight,workerTimes)){
                right = mid;
                //cout <<" right " << right <<"\n";
            }
            else{
                left = mid+1;
                //cout <<" left " << left <<"\n";
            }
        }
        return left;
    }
    
    int helper(long long maxTime,int mountainHeight,vector<int>& workerTimes){
        long long totalReducedHeight = 0;
        for(int time:workerTimes){
            long long maxHeight =  (-1 + sqrt(1 + 8 * maxTime / time)) / 2;
            //cout << maxHeight <<" ";
            totalReducedHeight += maxHeight;
            if (totalReducedHeight >= mountainHeight) {
                return 1;
            }
        }
        return totalReducedHeight >= mountainHeight;
    }
    
};