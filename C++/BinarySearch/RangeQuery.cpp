// interview bit
// https://www.interviewbit.com/old/problems/search-for-a-range/

#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &A, int B)
{

    int start = 0;
    int end = A.size() - 1;
    int mid;
    vector<int> x{INT_MAX, -1};
    int flag = 0;
    while (start <= end)
    {

        mid = (start + end) / 2;

        if (A[mid] == B)
        {
            flag = 1;
            x[0] = mid;
            end = mid - 1;
        }
        else if (A[mid] < B)
            start = mid + 1;
        else
            end = mid - 1;
    }
    if (flag == 0)
        x[0] = -1;
    else
        x[0] = min(start, x[0]);

    start = 0;
    end = A.size() - 1;
    flag = 0;
    while (start <= end)
    {

        mid = (start + end) / 2;

        if (A[mid] == B)
        {
            flag = 1;
            x[1] = mid;
            start = mid + 1;
        }
        else if (A[mid] < B)
            start = mid + 1;
        else
            end = mid - 1;
    }
    if (flag == 0)
        x[1] == -1;
    else
        x[1] = max(end, x[1]);
    return x;
}
