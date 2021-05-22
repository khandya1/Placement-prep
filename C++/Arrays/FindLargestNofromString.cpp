
////   https://www.interviewbit.com/problems/largest-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool comparator(string first, string second)
    {
        string one = first + second;
        string two = second + first;

        int i = 0;
        while (one[i] && two[i])
        {
            if (one[i] > two[i])
                return true;
            else if (one[i] < two[i])
                return false;
            ++i;
        }

        return false;
    }
    string largestNumber(const vector<int> &x)
    {

        vector<string> A;
        for (int i = 0; i < x.size(); i++)
            A.push_back(to_string(x[i]));

        sort(A.begin(), A.end(), comparator);

        string p = "";
        int c = 0;
        for (int i = 0; i < A.size(); i++)
        {
            p += A[i];/////////////////// p = p + A[i] was giving TLE 
            if (A[i] == "0")
                c++;
            //cout<<A[i]<<"\n";
        }
        if (c == A.size())
            return "0";
        else
            return p;
    }
};
