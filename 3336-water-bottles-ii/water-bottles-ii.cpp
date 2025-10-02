class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunkBottles = numBottles;
        while(numBottles>=numExchange){
            drunkBottles++;
            numBottles -= numExchange;
            numExchange++;
            numBottles++;
        }
        return drunkBottles;
    }
};