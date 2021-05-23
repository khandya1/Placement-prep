/// https://leetcode.com/problems/next-permutation/
///LC 31
////  https://www.interviewbit.com/problems/next-permutation/

/*steps:
1. find position where the decreasing array stops, for 1 3 5 4 2 , pos = 1
2. find number which is greater than number at pos from the end, here 4 , pos2 =3
3. swap number at ps and pos2
4. reverse the entire array from pos+1 to end
*/

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