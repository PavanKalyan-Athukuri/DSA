class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while(a||b||c){
            int a1 = a&1;
            int b1 = b&1;
            int c1 = c&1;
            //cout << a <<" "<<b<<"\n";
            //cout << a1 <<" "<<b1<<" "<<c1<<" "<<a<<" "<<b<<"\n";
            a = a>>1;
            b = b>>1;
            c = c>>1;
              if ((a1 | b1) != c1) {
                if (c1 == 1) {
                    // If c1 is 1 and a1|b1 is 0, one flip is needed
                    count++;
                } else {
                    // If c1 is 0 and a1|b1 is 1, count the number of 1s in a1 and b1
                    count += (a1 == 1) + (b1 == 1);
                }
            }
        }
        return count;
    }
};