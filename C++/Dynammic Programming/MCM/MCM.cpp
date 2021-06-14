using namespace std;
#include <bits\stdc++.h>

class Solution
{
public:
    int MCMRecr(vector<int> arr, int l, int r)
    {
        if (l == r)
            return 0;

        int minn = INT_MAX;
        int temp;
        for (int k = l; k < r; k++)
        {
            minn = min(minn, MCMRecr(arr, l, k) + MCMRecr(arr, k + 1, r) + arr[l - 1] * arr[k] * arr[r]);
        }
        return minn;
    }

    int MCMMemo(vector<int> arr, int l, int r, vector<vector<int>> &dp)
    {

        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        dp[l][r] = INT_MAX;

        for (int k = l; k < r; k++)
        {
            dp[l][r] = min(dp[l][r], MCMMemo(arr, l, k, dp) + MCMMemo(arr, k + 1, r, dp) + arr[l - 1] * arr[k] * arr[r]);
        }
        return dp[l][r];
    }
    int MCMDP(vector<int> arr, int l, int r, vector<vector<int>> &dp)
    {

        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        dp[l][r] = INT_MAX;

        for (int k = l; k < r; k++)
        {
            dp[l][r] = min(dp[l][r], MCMMemo(arr, l, k, dp) + MCMMemo(arr, k + 1, r, dp) + arr[l - 1] * arr[k] * arr[r]);
        }
        return dp[l][r];
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 3};
    Solution s;
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));

    cout << "Minimum number of multiplications is " << s.MCMDP(arr, 1, arr.size() - 1, dp);
}