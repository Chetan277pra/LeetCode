class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        vector<int> lower = rec1[1] < rec2[1] ? rec1 : rec2;
        vector<int> upper = rec1[1] > rec2[1] ? rec1 : rec2;
        if(lower[3] <= upper[1] ) return false;
        vector<int> left = rec1[0] < rec2[0] ? rec1 : rec2;
        vector<int> right = rec1[0] > rec2[0] ? rec1 : rec2;
        if(left[2] <= right[0] ) return false;
        return true;

    }
};