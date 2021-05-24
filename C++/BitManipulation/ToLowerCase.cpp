//  https://leetcode.com/problems/to-lower-case/
// lc709
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    string &toLowerCase(string &str)
    {
        for (char &c : str)
            c |= 0b00100000;
        return str;
    }
};