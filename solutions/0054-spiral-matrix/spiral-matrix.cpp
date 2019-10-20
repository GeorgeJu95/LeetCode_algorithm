// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
// Example 1:
//
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
//
//
// Example 2:
//
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0) return res;
        int i, x, y, m, n;
        x = y = 0;
        m = matrix.size(); n = matrix[0].size();
        bool flag[m][n];
        memset(flag, 0, sizeof(flag));
        res.emplace_back(matrix[x][y]);
        flag[x][y] = 1;
        i = 1;
        while(i < m*n) {
            while(y+1 < n && !flag[x][y+1]) {
                res.emplace_back(matrix[x][++y]);
                flag[x][y] = 1;
                ++i;
            }
            while(x+1 < m && !flag[x+1][y]) {
                res.emplace_back(matrix[++x][y]);
                flag[x][y] = 1;
                ++i;
            }
            while(y-1 >= 0 && !flag[x][y-1]) {
                res.emplace_back(matrix[x][--y]);
                flag[x][y] = 1;
                ++i;
            }
            while(x-1 >= 0 && !flag[x-1][y]) {
                res.emplace_back(matrix[--x][y]);
                flag[x][y] = 1;
                ++i;
            } 
        }
        return res;
    }
};
