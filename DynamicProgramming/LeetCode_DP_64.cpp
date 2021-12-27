class Solution {
    int memoization[201][201];
public:
    /**
     * @brief 0, 0으로부터 x, y까지의 최소 합을 구하는 함수
     * 
     * @param x 좌표
     * @param y 좌표
     * @param grid 그리드
     * @return int 최소 합
     */
    int minpath(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || y < 0) { // 좌표값이 비정상인 경우 0 리턴
            return 0;
        }
        if (memoization[x][y] != -1) { // 해당 좌표가 이미 계산된 이력이 있을 경우 기존 값 리턴
            return memoization[x][y];
        }
        int left = minpath(x - 1, y, grid);
        int up = minpath(x, y - 1, grid);
        if (x == 0) { // x좌표가 0일 경우 무조건 위에서 오는 경로만 생각한다.
            memoization[x][y] = grid[y][x] + up;
        } else if (y == 0) { // y좌표가 0일 경우 무조건 왼쪽에서 오는 경로만 생각한다.
            memoization[x][y] = grid[y][x] + left;
        } else { // 그 외에는 위와 왼쪽 중 어느 쪽이 최소거리인지 판단한다.
            memoization[x][y] = grid[y][x] + ((left > up) ? up : left);
        }
        return memoization[x][y];
    }
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                memoization[i][j] = -1; // 그리드엔 0도 올 수 있으므로 구분하기 위해 -1로 초기화
            }
        }
        return minpath(grid[0].size() - 1, grid.size() - 1, grid);
    }
};