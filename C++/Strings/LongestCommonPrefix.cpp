//////   https://www.interviewbit.com/problems/longest-common-prefix/



#include <bits/stdc++.h>
using namespace std;

class LongestCommonPrefix
{
    string longestCommonPrefix(vector<string> &A)
    {

        int len = A[0].size();
        int pos = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (len > A[i].size())
            {
                pos = i;
                len = A[i].size();
            }
        }
        string x = A[pos];
        string common = "";
        if (A.size() == 0)
            return common;

        for (int i = 0; i < x.size(); i++)
        {
            int j = 0, count = 0;
            while (j != A.size())
            {
                if (A[j][i])
                {
                    // cout<<A[j][i]<<";;;"<<x[i];
                    if (A[j][i] == x[i])
                        count++;
                    else
                        break;

                    if (count == A.size())
                    {
                        //cout<<x[i]<<count;
                        common += x[i];
                    }
                    j++;
                }
                else
                    break;
            }
        }
        return common;
    }

    string longestCommonPrefix1(vector<string> &A) /// editorial sorting approach
    {
        string s;
        //sorting the strings lexicographically
        sort(A.begin(), A.end());
        int m, n;
        m = A.size() - 1;
        n = min(A[0].length(), A[m].length());
        int i = 0;
        //first and last string will be most dissimilar thus finding common charcters in these
        while (i < n && A[0][i] == A[m][i])
        {
            s += A[0][i];
            i++;
        }
        return s;
    }
};
