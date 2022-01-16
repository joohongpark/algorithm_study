class Solution {
    int memoization[502][502];
public:
    int minDistance(string word1, string word2) {
        // 이 알고리즘에 정확히 대응되는 "레벤슈타인 거리" 라는 알고리즘이 있다.
        
        for(int i = 0; i < word1.length() + 1; i++) {
            for(int j = 0; j < word2.length() + 1; j++) {
                if (i < 1 || j < 1) {
                    memoization[j][i] = max(i, j);
                } else {
                    if (word1[i - 1] == word2[j - 1]) {
                        memoization[j][i] = memoization[j - 1][i - 1];
                    } else {
                        memoization[j][i] = min(
                            min(memoization[j][i - 1],
                                memoization[j - 1][i]),
                            memoization[j - 1][i - 1]) + 1;
                    }
                }
            }
        }
        return memoization[word2.length()][word1.length()];
    }
};