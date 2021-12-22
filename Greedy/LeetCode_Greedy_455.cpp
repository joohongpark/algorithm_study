class Solution {
public:
    /**
     * @brief 아이들의 원하는 만큼 쿠키를 분할해주는 문제
     * 
     * @param g 아이들 각각의 쿠키 크기 욕심
     * @param s 각 쿠키의 크기
     * @return int 만족시킬 수 있는 아이들의 숫자
     */
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int rtn = 0;
        // 쿠키의 크기 및 아이들이 원하는 크기를 오름차 순으로 정렬한다.
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // 이터레이터를 이용해서 접근한다.
        vector<int>::iterator gi = g.begin();
        vector<int>::iterator si = s.begin();
        // 모든 원소에 접근할 때 까지 루프를 돈다.
        while ((gi != g.end()) && (si != s.end())) {
            // 만약 현재 선택한 아이의 탐욕이 현재 선택한 쿠키의 크기를 만족시키면
            if (*gi <= *si) {
                // 둘 다 다음 이터레이터로 넘기며 만족시킨 아이의 인원수(rtn)를 늘린다.
                rtn++;
                gi++;
                si++;
            } else {
                // 그렇지 않으면 아이의 탐욕이 만족될만한 쿠키를 찾는다. 만약 end 이터레이터에 도달하면 루프를 멈춘다.
                si++;
            }
        }
        return (rtn);
    }
};