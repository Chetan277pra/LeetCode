class Solution {
public:
    int giveday(string s){
        // 31 59 90 120 151 181 212 243 273 304 334 365

        if(s.substr(0 , 2) == "01") 
           return (stoi(s.substr(3,2)));
        
        else if(s.substr(0 , 2) == "02") 
           return 31 + (stoi(s.substr(3,2)));

        else if(s.substr(0 , 2) == "03") 
           return 59 + (stoi(s.substr(3,2)));

        else if(s.substr(0 , 2) == "04") 
           return 90 + (stoi(s.substr(3,2)));

        else if(s.substr(0 , 2) == "05") 
           return 120 + (stoi(s.substr(3,2)));

        else if(s.substr(0 , 2) == "06") 
           return 151 + (stoi(s.substr(3,2)));

        else if(s.substr(0 , 2) == "07") 
           return 181 + (stoi(s.substr(3,2)));

        else if(s.substr(0 , 2) == "08") 
           return 212 + (stoi(s.substr(3,2)));

        else if(s.substr(0 , 2) == "09") 
           return 243 + (stoi(s.substr(3,2)));

        else if(s.substr(0 , 2) == "10") 
           return 273 + (stoi(s.substr(3,2)));
        
        else if(s.substr(0 , 2) == "11") 
           return 304 + (stoi(s.substr(3,2)));
        
        else
           return 334 + (stoi(s.substr(3,2)));

    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a = giveday(arriveAlice);
        int b = giveday(arriveBob);
        int c = giveday(leaveAlice);
        int d = giveday(leaveBob);
        // cout << a << " " << b << " " << c << " " << d << endl;
        if(min(c , d) < max(a , b)) return 0;
        return min(c , d) - max(a , b) + 1;
    }
};