using namespace std;
#include <bits/stdc++.h>

class Solution
{
    void rotate(vector<vector<int>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = i; j < A[i].size(); j++)
            {
                int temp = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = temp;
            }
        }
        for (int i = 0; i < A.size(); i++)
        {
            reverse(A[i].begin(), A[i].end());
        }
    }
};