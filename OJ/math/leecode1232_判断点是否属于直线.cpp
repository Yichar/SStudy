class Solution {
public:
    //利用 (y2 - y1 ) * (x2 - x1) = (y1 - y0) * (x1 - x0);
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() <= 2) return true;
        vector<int> v0 = coordinates[0];
        vector<int> v1 = coordinates[1];
        int resy = v1[1] - v0[1];
        int resx = v1[0] - v0[0];
        for (int i = 1; i < coordinates.size(); i++) {
            int tempy = coordinates[i][1] - coordinates[i-1][1];
            int tempx = coordinates[i][0] - coordinates[i-1][0];
            if (resy * tempx != resx * tempy)
                return false;
        }
        return true;
    }
};
