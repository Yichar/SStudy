/*************************************************************************
	> File Name: leecode304_二维矩阵区域和.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 二  3/ 2 11:50:53 2021
 ************************************************************************/
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
          return sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] - sum[row1][col2 + 1] + sum[row1][col1];
    }

    vector<vector<int> > sum = vector<vector<int>> (1005,vector<int>(1005,0));
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
