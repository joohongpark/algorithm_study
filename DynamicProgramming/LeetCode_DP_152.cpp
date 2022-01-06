class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minprod = nums[0];
        int maxprod = nums[0];
        int rtn = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int minprod_tmp = min(nums[i], min(nums[i] * maxprod, nums[i] * minprod));
            int maxprod_tmp = max(nums[i], max(nums[i] * maxprod, nums[i] * minprod));
            minprod = minprod_tmp;
            maxprod = maxprod_tmp;
            rtn = max(rtn, maxprod);
        }
        return rtn;
    }
};