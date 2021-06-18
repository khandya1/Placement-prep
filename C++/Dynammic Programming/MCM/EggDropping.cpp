

using namespace std;
#include <bits\stdc++.h>

class Solution
{
public:
    int EggDropping(int egg, int floor)
    {
        if (floor == 0 || floor == 1 || egg == 1)
            return floor;

        int mini = INT_MAX;
        for (int k = 1; k <= floor; k++)
        {
            int temp = 1 + max(EggDropping(egg - 1, k - 1), EggDropping(egg, floor - k)); // worst case is asked that's why maximum
            mini = min(mini, temp);
        }
        return mini;
    }
    int EggDroppingMemo(int egg, int floor, vector<vector<int>> dp)
    {
        if (floor == 0 || floor == 1 || egg == 1)
            return floor;

        if (dp[egg][floor] != -1)
            return dp[egg][floor];

        dp[egg][floor] = INT_MAX;
        for (int k = 1; k <= floor; k++)
        {
            int temp = 1 + max(EggDroppingMemo(egg - 1, k - 1, dp), EggDroppingMemo(egg, floor - k, dp)); // worst case is asked that's why maximum
            dp[egg][floor] = min(dp[egg][floor], temp);
        }
        return dp[egg][floor];
    }

    int EggDroppingDP(int egg, int floor, vector<vector<int>> dp)
    {
        for (int gap = 0; gap < dp[0].size(); gap++)
        {
            
            for (int i = 0, j = gap; i < dp.size() && j < dp[0].size(); i++, j++)
            {
                if (j == 0 || j == 1 || i == 1)
                    dp[i][j] = j;

                int x = (i - 1 && j - 1) ? dp[i - 1][j - 1] : 0;
                int y = (floor - j) ? dp[i][floor - j] : 0;

                int temp = 1 + max(x, y); // worst case is asked that's why maximum
                dp[i][j] = min(dp[i][j], temp);
            }
        }
        return dp[egg][floor];
    }
};

int main()
{
    int n = 2, k = 10;
    Solution s;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    cout << "Minimum number of trials "
            "in worst case with "
         << n << " eggs and " << k
         << " floors is " << s.EggDroppingDP(n, k, dp) << endl;
    return 0;
}