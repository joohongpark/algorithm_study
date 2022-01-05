class Solution {
public:
    /**
     * @brief n개의 문자를 만들고자 할 때 키보드를 누르는 횟수
     * 
     * @param n 화면에 띄울 A의 개수
     * @return int 키보드를 누르는 횟수
     */
    int minSteps(int n) {
        if (n == 1) { // A가 1이면 누를 필요 없음
            return (0);
        } else if (n == 2) { // A를 두개 만드려면 C->V 두번 누름
            return (2);
        } else {
            /**
             * n이 만약 다른 숫자로 나누어 떨어지면 (작은 숫자 * 큰 숫자) 형태이다.
             * 여기서 작은 숫자만큼 V 버튼을 큰 숫자(문자열 길이) 만큼 누른것이 된다.
             * 만약 나누어 떨어지는 숫자가 없다면 숫자를 그 길이만큼 누른 것이다.
             * 33이란 숫자는 N이 1000까지 가능한데 그 값의 제곱근이다.
             */
            for (int i = 2; i < 33; i++) {
                if (n % i == 0) {
                    return (minSteps(n / i) + i);
                }
            }
            return (n);
        }
    }
};