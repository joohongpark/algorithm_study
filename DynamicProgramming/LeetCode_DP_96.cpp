class Solution {
    int memoization[20];
public:
    Solution() {
        for (int i = 0; i < 20; i++) {
            memoization[i] = -1;
        }
    }
    int numTrees(int n) {
        if (n < 2) {
            return 1;
        }
        if (memoization[n] != -1) {
            return memoization[n];
        }
        memoization[n] = 0;
        for (int i = 0; i <= n - 1; i++) {
            memoization[n] += numTrees(i) * numTrees(n - 1 - i);
        }
        return memoization[n];
    }
};