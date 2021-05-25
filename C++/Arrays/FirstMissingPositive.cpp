///////   https://leetcode.com/problems/first-missing-positive/
/// lc 41


#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //// takes more time
    int firstMissingPositiveLT(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (nums[i] > 0 and nums[i] <= n and nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
    ///// short time

    int firstMissingPositive(vector<int> &nums)
    {
        // ans can never be greater than nums.size() + 2
        // ans can never be <= 0
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 0)
                nums[i] = n + 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (abs(nums[i]) <= nums.size() and nums[abs(nums[i]) - 1] >= 1)
            {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }

    ///// TLE but accepted in interview bit

    int firstMissingPositiveTLE(vector<int> &nums)
    {
        int max = *max_element(A.begin(), A.end());
        if (max <= 0)
            return 1;
        vector<int> arr(max, -1);
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] <= 0)
                continue;
            if (A[i] == max)
                continue;
            arr[A[i]] = 1;
        }
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] == -1)
                return i;
        }
        return max + 1;
    }
};