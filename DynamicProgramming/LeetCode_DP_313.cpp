class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int* uglys = new int[n];
        uglys[0] = 1;
        vector<int> pos(primes.size(), 0);
        int index = 1;
        while (index != n) {
            int next_ugly = INT_MAX;
            for (int i = 0; i < primes.size(); i++) {
                int uglys_tmp = uglys[pos[i]] * primes[i];
                if (next_ugly > uglys_tmp) {
                    next_ugly = uglys_tmp;
                }
            }
            for (int i = 0; i < primes.size(); i++) {
                if (next_ugly == uglys[pos[i]] * primes[i]) {
                    pos[i]++;
                }
            }
            uglys[index] = next_ugly;
            index++;
        }
        int rtn = uglys[index - 1];
        delete uglys;
        return rtn;
    }
};