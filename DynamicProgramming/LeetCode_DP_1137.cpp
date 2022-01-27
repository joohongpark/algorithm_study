class Solution {
    int memoization[38];
public:
    Solution() {
        for (int i = 0; i < 38; i++) {
            memoization[i] = -1;
        }
        memoization[0] = 0;
        memoization[1] = 1;
        memoization[2] = 1;
    }
    int tribonacci(int n) {
        if (memoization[n] == -1) {
            memoization[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        }
        return memoization[n];
    }
};