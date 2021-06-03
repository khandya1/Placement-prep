// number of subsets , reference taken from GFG shows how backtracking works with recurrsive tree
// https://leetcode.com/problems/permutations/
// LC46 Medium
// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int> &nums)
    {

        return dfs(nums, 0, nums.size() - 1);
    }
    vector<vector<int>> dfs(vector<int> nums, int l, int r)
    {
        if (l == r)
        {
            res.push_back(nums);

            return res;
        }
        for (int i = l; i <= r; i++)
        {

            swap(nums[l], nums[i]);
            dfs(nums, l + 1, r);
            swap(nums[i], nums[l]);
        }
        return res;
    }
};