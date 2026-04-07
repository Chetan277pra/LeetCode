class Robot {
public:
    vector<tuple<int,int,int>> pos;
    int col, row;
    int cyc;
    int ind = 0;
    bool chla = false;
    Robot(int width, int height) {
        col = width;
        row = height;

        // bottom row
        for(int i = 0; i < col; i++)
            pos.push_back({i, 0, 0});

        // right column
        for(int i = 1; i < row; i++)
            pos.push_back({col-1, i, 1});

        // top row
        for(int i = col-2; i >= 0; i--)
            pos.push_back({i, row-1, 2});

        // left column
        for(int i = row-2; i > 0; i--)
            pos.push_back({0, i, 3});
        get<2>(pos[0]) = 3;
        cyc = pos.size();
    }
    
    void step(int num) {
        chla = true;
        num %= cyc;
        if(num == 0) num = cyc;  

        ind = (ind + num) % cyc;
    }
    
    vector<int> getPos() {
        return {get<0>(pos[ind]), get<1>(pos[ind])};
    }
    
    string getDir() {
        int d = get<2>(pos[ind]);
        if(!chla ) return "East";
        if(d == 0) return "East";
        if(d == 1) return "North";
        if(d == 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */