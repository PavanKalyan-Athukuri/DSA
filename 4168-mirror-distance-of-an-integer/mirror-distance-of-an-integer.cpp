class Solution {
public:
    int mirrorDistance(int n) {
        int curr = n;
        int rev=0;
        while(n){
            int temp = n%10;
            rev = rev*10+temp;
            n = n/10;
        }
        return abs(rev-curr);
    }
};