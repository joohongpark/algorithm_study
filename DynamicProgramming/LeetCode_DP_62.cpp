class Solution {
    int memoization[101][101];
public:
    /**
     * @brief 메모이제이션 배열 원소를 -1로 초기화 하기위한 기본 생성자
     * 
     */
    Solution() {
        for (int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                memoization[i][j] = -1;
            }
        }
    }
    /**
     * @brief (1, 1) 부터 (n, m) 까지 도달 가능한 경로를 구하는 로직
     * 
     * @param m y축
     * @param n x축
     * @return int 
     */
    int uniquePaths(int m, int n) { // m : y , n : x
        if (m < 1 || n < 1) { // (n, m) 이 도달 가능한 범위를 벗어날 경우 0 리턴
            return 0;
        }
        if (memoization[m][n] != -1) { // 메모이제이션
            return memoization[m][n];
        }
        if (m == 1 && n == 1) {
            // 왜 원점인 (1, 1)에 대한 경로가 1인지 모르겠음. 0이라면 별도로 처리 필요
            memoization[m][n] = 1;
        } else {
            memoization[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1); // 왼쪽, 위쪽의 경로를 더함
        }
        return memoization[m][n];
    }
};