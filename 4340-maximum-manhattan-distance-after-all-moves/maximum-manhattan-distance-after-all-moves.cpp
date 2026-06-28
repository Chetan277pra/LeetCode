class Solution {
public:
    int maxDistance(string moves) {
        int side = 0;
        int uppar = 0;
        int dash  = 0;
        for(auto a : moves){
            if(a == 'L') side--;
            else if(a == 'R') side++;
            else if(a == 'U') uppar++;
            else if(a == 'D') uppar--;
            else dash++;
        }
        // cout << side << " " << uppar << endl;
        if(abs(side) > abs(uppar)){
            if(side < 0) side -= dash;
            else side+= dash;
        }
        else{
            if(uppar < 0) uppar -= dash;
            else uppar += dash;
        }
        return (abs(side) + abs(uppar));
    }
};