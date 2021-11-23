class Solution {
public:
    string longestPalindrome(string s) {
        size_t width = 0;
        size_t pos = 0;
        string rtn;
        for(size_t i = 0; i < s.length(); i++) {
            size_t w1 = find_palindromic_odd(s, i);
            size_t w2 = find_palindomic_even(s, i);
            if (width < w1 || width < w2) {
                pos = i;
                if (w1 > w2) {
                    rtn = s.substr(i - ((w1 - 1) / 2), w1);
                } else {
                    rtn = s.substr(i - ((w2 / 2) - 1), w2);
                }
                width = max(w1, w2);
            }
        }
        return (rtn);
    }
    size_t find_palindromic_odd(string& s, size_t pos) {
        size_t half_width = 0;
        while (true) {
            half_width++;
            if ((s.length() > (pos + half_width)) && (half_width <= pos) && (s[pos - half_width] == s[pos + half_width])) {
                continue;
            } else {
                half_width--;
                break;
            }
        }
        return half_width * 2 + 1;
    }
    size_t find_palindomic_even(string& s, size_t pos) {
        // pos, pos + 1
        size_t half_width = 0;
        while (true) {
            if ((s.length() > (pos + half_width + 1)) && (half_width <= pos) && (s[pos - half_width] == s[pos + 1 + half_width])) {
                half_width++;
            } else {
                break;
            }
        }
        return half_width * 2;
    }
};