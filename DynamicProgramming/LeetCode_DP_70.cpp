class Solution {
    int memoization[46];
public:
    Solution() {
        for (int i = 0; i < 46; i++) {
            memoization[i] = -1;
        }
    }
    int climbStairs(int n) {
        if (n == 0) {
            return 1;
        } else if (n < 0) {
            return 0;
        }
        if (memoization[n] != -1) {
            return memoization[n];
        }
        memoization[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return memoization[n];
    }
};