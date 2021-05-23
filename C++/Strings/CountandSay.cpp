//// https://leetcode.com/problems/count-and-say/
/// lc 38
//// https://www.interviewbit.com/problems/count-and-say/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

    string countAndSay(int n)
    {
        string res = "1";
        n--;
        while (n--)
        {
            string cur = "";
            for (int i = 0; i < res.size(); i++)
            {
                int count = 1;
                while ((i + 1 < res.size()) && (res[i] == res[i + 1]))
                {
                    count++;
                    i++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
    string TLE(int n)
    {
        int count = 1;

        string p = "1";
        if (n == 1)
            return "1";
        n--;
        while (n--)
        {
            p = cands(p);
        }
        return p;
    }
    string cands(string x)
    {
        string s = "";
        int count = 0;
        char val = x[0];
        for (int i = 0; i < x.size(); i++)
        {
            if (val == x[i])
                count++;
            else
            {
                s = s + to_string(count) + val;
                count = 1;
                val = x[i];
            }
        }
        s += to_string(count) + val;
        return s;
    }
};