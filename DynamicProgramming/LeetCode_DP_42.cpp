class Solution {
    int maxL[20000];
    int maxR[20000];
public:
    int trap(vector<int>& height) {
        int maxh = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            // maxR 찾는 로직
            maxh = max(maxh, height[i + 1]);
            maxR[i] = maxh;
        }
        maxh = height[0];
        for (int i = 1; i < height.size(); i++) {
            // maxL 찾는 로직
            maxh = max(maxh, height[i - 1]);
            maxL[i] = max(maxh, height[i - 1]);
        }
        int rtn = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            int tmp = min(maxL[i], maxR[i]) - height[i];
            rtn += (tmp > 0) ? tmp : 0;
        }
        return rtn;
    }
};