class Solution {
    size_t memoization[100001];
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    size_t cntVowelsFromPos(string& word, int pos) {
        if (word.length() == pos) {
            return 0;
        }
        if (memoization[pos] != -1) {
            return memoization[pos];
        }
        if (isVowel(word[pos])) {
            memoization[pos] = cntVowelsFromPos(word, pos + 1) + word.length() - pos;
        } else {
            memoization[pos] = cntVowelsFromPos(word, pos + 1);
        }
        return memoization[pos];
    }
public:
    size_t countVowels(string word) {
        size_t rtn = 0L;
        for (int i = 0; i < word.length(); i++) {
            memoization[i] = -1;
        }
        for (int i = 0; i < word.length(); i++) {
            rtn += cntVowelsFromPos(word, i);
        }
        return rtn;
    }
};