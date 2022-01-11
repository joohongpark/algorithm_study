class Solution {
    int memoization[100][100];
private:
/**
 * @brief (0, 0) 에서 (x, y)까지 도달 가능한 경로의 수를 구하는 함수
 * 
 * @param x 
 * @param y 
 * @param obstacleGrid 장애물이 있는 위치를 나태는 배열
 * @return int 경로의 수
 */
    int getPath(int x, int y, vector<vector<int>>& obstacleGrid) {
        if (x < 0 || y < 0 || (obstacleGrid[y][x] == 1)) {
            return 0;
        }
        if (memoization[y][x] != -1) {
            return memoization[y][x];
        }
        int up = getPath(x, y - 1, obstacleGrid);
        int left = getPath(x - 1, y, obstacleGrid);
        memoization[y][x] = up + left;
        return memoization[y][x];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[0].size(); j++) {
                memoization[i][j] = -1;
            }
        }
        memoization[0][0] = 1; // (0, 0)에서 출발할 때는 1로 친다.
        return getPath(obstacleGrid[0].size() - 1, obstacleGrid.size() - 1, obstacleGrid);
    }
};