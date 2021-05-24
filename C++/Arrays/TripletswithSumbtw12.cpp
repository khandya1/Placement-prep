// ////   https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/


//  take account of the fact that we want to check all the triplets not just ones in sequence, so 
//  if the sum goes more than 2 reduce the value else if sum goes less than 1 increase the value 

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int solve(vector<string> &A)
    {
        vector<double> b(A.size());
        for (int i = 0; i < A.size(); i++)
        {
            b[i] = stod(A[i]);
        }
        double a1 = b[0];
        double a2 = b[1];
        // double a = 0;
        double t = 0;
        for (int i = 2; i < b.size(); i++)
        {
            t = a1 + a2 + b[i];
            if (t > 1 && t < 2)
                return 1;
            if (t >= 2 && (a1 > b[i] || a2 > b[i]))
            {
                a1 = min(a1, a2);
                a2 = b[i];
            }
            if (t <= 1 && (b[i] > a1 || b[i] > a2))
            {
                a1 = max(a1, a2);
                a2 = b[i];
            }
        }
        return 0;
    }
};