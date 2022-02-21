class Solution {
    int memoization[101];
public:
    Solution() {
        for (int i = 0; i < 101; i++) {
            memoization[i] = -1;
        }
    }
    int rest(size_t pos, vector<int>& nums) {
        if (pos >= nums.size()) {
            return 0;
        } else if (pos == (nums.size() - 1)) {
            return nums[pos];
        } else if (pos == (nums.size() - 2)) {
            return max(nums[pos], nums[pos + 1]);
        }
        if (memoization[pos] != -1) {
            return memoization[pos];
        }
        int a = nums[pos] + rest(pos + 2, nums);
        int b = nums[pos + 1] + rest(pos + 3, nums);
        memoization[pos] = max(a, b);
        return memoization[pos];
    }
    int rob(vector<int>& nums) {
        return rest(0, nums);
    }
};