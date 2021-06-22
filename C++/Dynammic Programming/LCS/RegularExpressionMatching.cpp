#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {

        return lcs(s, p, s.size() - 1, p.size() - 1);
    }
    bool lcs(string s, string p, int m, int n)
    {
        if (n == -1 && m == -1)
            return true;
        if (m != -1 && n == -1)
            return false;
        if (m == -1 && n != -1)
        {
            if (p[n] == '*')
                return lcs(s, p, m, n - 2);
            else
                return false;
        }

        else
        {
            if (s[m] == p[n] || p[n] == '.')
                return lcs(s, p, m - 1, n - 1);

            else if (p[n] == '*')
            {
                if (p[n - 1] == s[m] || p[n - 1] == '.')
                    return lcs(s, p, m - 1, n) || lcs(s, p, m, n - 2);

                else
                    return lcs(s, p, m, n - 2);
            }

            else
                return false;
        }
    }
};