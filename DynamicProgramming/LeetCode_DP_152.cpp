class Solution {
public:
/**
 * @brief 인자로 입력된 배열의 부분 배열 중 부분 배열 원소간의 곱 중 최댓값을 구하는 함수
 * 
 * @param nums 배열
 * @return int 최댓값
 */
    int maxProduct(vector<int>& nums) {
        /**
         * minmul, maxmul은 특정 지점부터 순회하는 순간까지의 최댓값, 최소값을 저장한다.
         * 최댓값, 최소값은 다음과 같이 산정된다.
         * - 다음 순회할 지점 그 자체의 값 * 최댓값과 다음 순회할 지점 그 자체의 값 * 최소값 비교
         * - 위에서 비교한 값과 다음 순회할 지점 그 자체의 값 비교
         * 이렇게 비교하는 이유는 (최소값을 가지고 있는 이유는) 배열 내 음수 때문에 최소값이 최대값이 될 여지가 있다.
         * 그리고 위에서 계산한 최댓값은 곧 리턴값이 되지는 않으며 순회를 돌때마다 작아질 수도 있으므로 최댓값은 별도로 체크한다.
         * 
         * 예를 들어 배열 원소가 [2, 3, -2, 4] 라고 한다면
         * 처음 최대값, 최소값, 리턴할 값은 모두 2가 된다.
         * 순회는 다음 원소부터 돌게 되는데 이 때 최댓값, 최소값, 리턴할 값은 각각 6, 3, 6이 된다.
         * 다음 순회의 각 값은 -2, -12, 6이 된다. 최댓값이 -2가 된 이유는 음수 때문이며 2부터 시작되어 이어질 수 있는 최댓값의 단절 또한 의미한다.
         * 다음 순회의 각 값은 -48, 4, 6이 된다. 결과적으로 최대값은 6이 된다.
         * 
         * 만약에 배열 원소가 [2, 3, -2, 4, -1] 가 된다면 위에서 -48이 -1 때문에 48이 되어 최댓값은 48이 된다.
         */
        int minmul = nums[0];
        int maxmul = nums[0];
        int rtn = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int minmul_tmp = min(nums[i], min(nums[i] * maxmul, nums[i] * minmul));
            int maxmul_tmp = max(nums[i], max(nums[i] * maxmul, nums[i] * minmul));
            minmul = minmul_tmp;
            maxmul = maxmul_tmp;
            rtn = max(rtn, maxmul);
        }
        return rtn;
    }
};