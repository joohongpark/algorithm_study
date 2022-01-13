class Solution {
    int memoization[10001];
public:
    /**
     * @brief 인수 amount 값에 대해 coins 내에 있는 배열로 조합할 수 있는 최소값을 리턴하는 함수
     * 
     * 동작 원리
     *  recursive([1, 2, 3], 5) 로 주어진다면
     *   - 5 - 1 -> recursive([1, 2, 3], 4) + 1
     *   - 5 - 2 -> recursive([1, 2, 3], 3) + 1
     *   - 5 - 3 -> recursive([1, 2, 3], 2) + 1
     *  가 호출되며,
     *  재귀 호출 함수 중 recursive([1, 2, 3], 4) 에 대해선
     *   - 4 - 1 -> recursive([1, 2, 3], 3) + 1
     *   - 4 - 2 -> recursive([1, 2, 3], 2) + 1
     *   - 4 - 3 -> recursive([1, 2, 3], 1) + 1
     *  가 호출되며,
     *  재귀 호출 함수 중 recursive([1, 2, 3], 3) 에 대해선
     *   - 3 - 1 -> recursive([1, 2, 3], 2) + 1
     *   - 3 - 2 -> recursive([1, 2, 3], 1) + 1
     *   - 3 - 3 -> 0 -> 1 (인수 3에 대해서 3을 한번 사용하면 조합 가능하므로 '1' 이다.)
     * 
     * 위 사례처럼 배열 원소 중 amount에 대응되는 값이 있으면 1을 리턴하며
     * recursive 함수의 리턴값이 -1이 아니면 위와 같이 +1을 해나간다.
     * 그런 다음, 유효한 (배열에 대해 재귀 함수가 정상적으로 동작한 경우를 의미한다.) 조건에 대해서 최소값을 뽑아
     * 리턴하며, 메모이제이션 한다.
     * 
     * 문재의 핵심은 재귀적으로 top-down 방식을 사용하여 찾는 것이며
     * 피보나치 수열과 약간 유사한 방식이다.
     * 이와 비슷한 문제는 (계단 오르기) 문제가 있다.
     * 
     * 위 문제들에 비해 최소값을 구하는 것이 목적이므로 다소 복잡한 면이 있으며
     * 문제가 BFS에 속하긴 하지만 단순 BFS로 풀기는 어려운 문제이다.
     * 
     * @param coins 동전 배열
     * @param amount 
     * @return int 배열로 조합할 수 있는 최소값
     */
    int recursive(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (memoization[amount] != -2) {
            return memoization[amount];
        }
        int m = INT_MAX;
        for (int i = coins.size() - 1; i >= 0; i--) {
            int tmp = amount - coins[i];
            if (tmp == 0) {
                return 1;
            } else if (tmp > 0) {
                int tmp1 = recursive(coins, tmp);
                if (tmp1 > 0) {
                    m = min(m, tmp1 + 1);
                }
            }
        }
        memoization[amount] = (m == INT_MAX) ? -1 : m;
        return memoization[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        for (int i = 0; i <= 10000; i++) {
            memoization[i] = -2;
        }
        return recursive(coins, amount);
    }
        
};