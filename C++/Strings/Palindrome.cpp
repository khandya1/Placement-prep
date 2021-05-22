/////  https://www.interviewbit.com/problems/palindrome-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int isPalindrome(string A)
    {

        transform(A.begin(), A.end(), A.begin(), ::tolower);
        int i = 0, j = A.size() - 1;
        while (i <= j)
        {
            if (!isalnum(A[i]))
            {
                i++;
                continue;
            }
            if (!isalnum(A[j]))
            {
                j--;
                continue;
            }
            if (A[i] != A[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
};