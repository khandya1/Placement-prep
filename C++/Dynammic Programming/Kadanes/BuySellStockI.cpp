
/// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solution/
// another slution included creating another dp storing the differences and finding max contigious sum array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        if (prices.size() <= 1)
            return 0;

        int minelement = prices[0];
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            minelement = min(minelement, prices[i]);
            maxprofit = max(prices[i] - minelement, maxprofit);
        }
        return maxprofit;
    }
};