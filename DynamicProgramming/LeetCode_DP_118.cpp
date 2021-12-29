class Solution {
    /**
     * @brief 인수로 가장 아래쪽의 줄이 입력되면 바로 밑의 새 줄을 만들어 주는 함수
     * 
     * @param row 가장 아래쪽의 줄
     * @return vector<int> 새로 추가될 새 줄
     */
    vector<int> genrow(vector<int>& row) {
        vector<int> rtn(row.size() + 1, 1);
        for (int i = 1; i < row.size(); i++) {
            rtn[i] = row[i - 1] + row[i];
        }
        return rtn;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rtn;
        rtn.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; i++) {
            rtn.push_back(genrow(rtn[i - 1]));
        }
        return rtn;
    }
};