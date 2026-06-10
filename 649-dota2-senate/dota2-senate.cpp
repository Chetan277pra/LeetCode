class Solution {
public:
    string predictPartyVictory(string senate) {
        int cntr = 0, cntd = 0, minr = 0, mind = 0;
        queue<char> q;
        for(auto a : senate){
            q.push(a);
            (a == 'R')?cntr++ : cntd++; 
        }
        while(1){
            if(cntr == 0) return "Dire";
            if(cntd == 0) return "Radiant";

            char ch = q.front();
            q.pop();
            if(ch == 'R'){
                if(minr > 0) cntr--, minr--;
                else mind++, q.push(ch);
            }
            else{
                if(mind > 0) cntd--, mind--;
                else minr++, q.push(ch);
            }
        }
        return "Chetan";
    }
};