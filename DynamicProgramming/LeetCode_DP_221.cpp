class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int memoization[300][300];
        int rtn = 0;
        for (int y = 0; y < matrix.size(); y++) {
            for (int x = 0; x < matrix[0].size(); x++) {
                if (x == 0 || y == 0) {
                    memoization[y][x] = (matrix[y][x] == '1') ? 1 : 0;
                } else {
                    if (matrix[y][x] == '0') {
                        memoization[y][x] = 0;
                    } else {
                        if ((matrix[y - 1][x - 1] == '1') && (matrix[y - 1][x] == '1') && (matrix[y][x - 1] == '1')) {
                            memoization[y][x] = min(
                                min(memoization[y][x - 1], memoization[y - 1][x]),
                                memoization[y - 1][x - 1]) + 1;
                        } else {
                            memoization[y][x] = 1;
                        }
                    }
                }
                rtn = max(rtn, memoization[y][x]);
            }
        }
        return rtn * rtn;
    }
};