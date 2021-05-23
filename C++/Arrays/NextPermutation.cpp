/// https://leetcode.com/problems/next-permutation/
///LC 31
////  https://www.interviewbit.com/problems/next-permutation/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<int> nextPermutation(vector<int> &A)
    {
        int pos = 0;
        for (int i = A.size() - 1; i >= 1; i--)
        {
            if (A[i] > A[i - 1])
            {
                pos = i - 1;
                break;
            }
        }
        int pos2 = A.size() - 1;
        for (int i = A.size() - 1; i >= pos; i--)
        {
            if (A[i] > A[pos])
            {
                pos2 = i;
                break;
            }
        }
        int temp = A[pos];
        A[pos] = A[pos2];
        A[pos2] = temp;
        pos = pos + 1;
        reverse(A.begin() + pos, A.end());

        return A;
    }
    void nextPermutation1(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
    }
};