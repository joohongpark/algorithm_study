class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int rtn = nums.back();
        int sum = 0;
        while (nums.size() > 0) {
            // 단순 계산 시에는 O(n^2)가 되지만 이전 부분배열의 최댓값을 메모이제이션 하면 O(n^2)가 됨.
            // sum은 부분배열을 탐색하며 계속 변하기 때문에 중간중간에 최댓값을 갱신하여야 함.
            int p = nums.back();
            nums.pop_back();
            sum = max(p, p + sum);
            rtn = max(rtn, sum);
        }
        return rtn;
    }
};