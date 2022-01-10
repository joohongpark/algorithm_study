class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = prices[0];
        int rtn = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            int buy_tmp = min(buy, prices[i]);
            int sell_tmp = (buy != buy_tmp) ? prices[i] : max(sell, prices[i]);
            rtn = max(rtn, sell_tmp - buy_tmp);
            buy = buy_tmp;
            sell = sell_tmp;
        }
        return rtn;
    }
};