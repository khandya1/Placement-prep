// https://www.interviewbit.com/problems/find-permutation/

// lc 484
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<int> findPerm(const string A, int B)
    {

        vector<int> x;
        int k = 1;
        if (A[0] == 'D')
            x.push_back(B--);
        if (A[0] == 'I')
            x.push_back(k++);

        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] == 'D')
            {
                x.push_back(B--);
            }
            else
            {
                x.push_back(k++);
            }
        }
        x.push_back(k);
        return x;
    }
};
