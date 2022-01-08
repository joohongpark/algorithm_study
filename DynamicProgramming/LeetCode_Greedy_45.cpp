class Solution {
public:
    /**
     * @brief 배열의 원소들이 현재 인덱스에서 다른 인덱스로 이동 가능한 최대 거리를 나타낼 때 최소 이동 횟수
     * 
     * @param nums 배열
     * @return int 최소 이동 횟수
     */
    int jump(vector<int>& nums) {
        int rtn = 0;
        int prevmax = 0;
        int nextmax = 0;
        /**
         * @brief   배열의 0번째 인덱스부터 마지막 인덱스 바로 전까지 순회하며
         *          순회하는 인덱스에서 도달 가능한 최댓값을 갱신한다.
         *          만약 현재 인덱스가 기존에 기록한 도달 가능한 최댓값과 같을 경우
         *          그 위치에서 다른 위치로 건너 뛴 것으로 친다.
         *          문제 조건이 배열의 원소들은 항상 마지막 인덱스까지 건너 뛰는 것을 보증한다.
         */
        for (int i = 0; i < nums.size() - 1; i++) {
            nextmax = max(nextmax, i + nums[i]);
            if (i == prevmax) {
                rtn++;
                prevmax = nextmax;
            }
        }
        return rtn;
    }
};