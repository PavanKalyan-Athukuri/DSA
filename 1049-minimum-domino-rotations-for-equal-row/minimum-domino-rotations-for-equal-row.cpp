class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int topRow[7] = {0};
        int bottomRow[7] = {0};
        int size = tops.size();
        for(int i=0;i<size;i++){
            topRow[tops[i]]++;
            bottomRow[bottoms[i]]++;
        }
        int count=0;
        bool inside = false;
        int min1 = 100000000;
        for(int i=1;i<7;i++){
            if(topRow[i]+bottomRow[i]>=size){
                inside = true;
                if(topRow[i]>=bottomRow[i]){
                    for(int j=0;j<size;j++){
                        if(tops[j]==i)
                            continue;
                        else if(bottoms[j]==i&&tops[j]!=bottoms[j]){
                            count++;
                        }
                        else return -1;
                    }
                }
                else if(topRow[i]<bottomRow[i]){
                    for(int j=0;j<size;j++){
                        if(bottoms[j]==i)
                            continue;
                        else if(tops[j]==i&&tops[j]!=bottoms[j]){
                            count++;
                        }
                        else return -1;
                    }
                }
                min1 = min(min1,count);
            }
        }
        if(!inside)
        return -1;
        return min1;
    }
};