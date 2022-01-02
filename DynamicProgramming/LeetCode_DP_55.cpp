class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        /**
        * dp는 해당 인덱스에서 이동 가능한 최대 거리를 의미한다.
        */
        dp[0] = nums[0]; // 처음 인덱스에서 이동 가능한 최대 거리를 저장한다.
        for (int i = 1; i < nums.size() - 1; i++) {
            int target_a = dp[i - 1]; // target_a는 이전 값에서 여기까지 도달하는지, 도달하면 어디까지 도달하는지를 의미한다.
            if (target_a < i) { // 이전 값에서 여기까지 도달할 수 없으면 절대로 마지막 인덱스까지 도달할 수 없다.
                break;
            }
            int target_b = nums[i] + i; // target_b는 만약 0에서 여기까지 어떻게든 도달한다면 그 최대거리가 얼마인지를 의미한다.
            dp[i] = max(target_a, target_b); // 둘 중 긴 거리를 취해 dp에 저장한다.
            if (dp[i] >= (nums.size() - 1)) { // 만약 현재 위치에서 이동 가능한 거리가 마지막 인덱스까지 도달 가능하면 더 찾아볼 필요가 없다.
                return true;
            }
        }
        return (nums.size() == 1) || (dp[0] >= (nums.size() - 1)); // 배열 길이가 1인 경우 무조건 true이며 배열 길이가 2인 경우도 별도로 체크한다.
    }
};