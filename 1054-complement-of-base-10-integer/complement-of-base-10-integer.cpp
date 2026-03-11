class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0;
        int count = -1;
        if(n==0)
        return 1;
        while(n){
            int rem = n%2;
            n = n/2;
            count++;
            if(!rem){
                ans = ans+pow(2,count);
            }
            // cout << "n " << n <<"\n";
            // cout << "rem "<< rem<<"\n";
            // cout << "count "<<count <<"\n";
        }
        return ans;
    }
};