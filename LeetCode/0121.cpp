class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max, min;
        max = min = prices.back();

        int ans = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            if (max < prices[i])
                max = min = prices[i];
            else if (min > prices[i]) {
                min = prices[i];
                ans = std::max(ans, max - min);
            }
        }

        return ans;
    }
};
