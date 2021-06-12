#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int lcsrecur(string X, string Y, int m, int n)
    {
        if (m == 0 || n == 0)
            return 0;
        if (X[m - 1] == Y[n - 1])
            return 1 + lcsrecur(X, Y, m - 1, n - 1);
        else
            return max(lcsrecur(X, Y, m, n - 1), lcsrecur(X, Y, m - 1, n));
    }

    int lcs(string X, string Y, int m, int n)
    {
        int L[m + 1][n + 1];
        int i, j;

        for (i = 0; i <= m; i++)
        {
            for (j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    L[i][j] = 0;

                else if (X[i - 1] == Y[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;

                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }

        return L[m][n];
    }
};