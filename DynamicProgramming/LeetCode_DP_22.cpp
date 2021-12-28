class Solution {
    /**
     * @brief 괄호의 왼쪽 '('과 오른쪽 ')'을 조합하여 사용 가능한 괄호가 둘 다 0이 될 때까지 탐색을 하는 함수이다.
     * 
     * @param rtn 조합이 완료될 때 결과물을 삽입하는 벡터
     * @param str 조합중인 문자열 (depth가 커질수록 문자열이 쌓임)
     * @param l 사용 가능한 ')' 괄호 개수
     * @param r 사용 가능한 '(' 괄호 개수
     */
    void dfs(vector<string>& rtn, string str, int l, int r) {
        if (l == 0 && r == 0) {
            // 괄호를 모두 사용했으면 조합해온 문자열 추가
            rtn.push_back(str);
            return ;
        }
        if (l > 0) {
            // '(' 문자가 사용 가능하다면 str에 문자를 추가하고 l - 1 함.
            dfs(rtn, str + "(", l - 1, r);
        }
        if (r > l) {
            // 사용 가능한 ')' 문자가 '(' 문자보다 많으면 str에 ')' 문자를 추가하고 r - 1 함.
            dfs(rtn, str + ")", l, r - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rtn;
        dfs(rtn, "", n, n); // 초기는 '(', ')' 모두 n만큼 사용 가능하다.
        return rtn;
    }
};