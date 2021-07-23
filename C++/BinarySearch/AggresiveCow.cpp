#include <bits/stdc++.h>
using namespace std;
bool canarrange(vector<int> x, int mid, int k)
{
    int count = 1; /// already placing in first position

    int i = 0, j = 1;
    while (j < x.size())
    {
        if (x[j] - x[i] >= mid)
        {
            count++;
            i = j;
            j++;
        }

        else
            j++;

        if (count >= k)
            return true;
    }

    return false;
}
int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        int n, k;
        vector<int> x;

        cin >> n;

        cin >> k;
        int mini = INT_MAX, maxi = INT_MIN;
        while (n--)
        {
            int p;
            cin >> p;
            x.push_back(p);
            maxi = max(maxi, p);
        }

        sort(x.begin(), x.end());
        mini = 0;
        int ans = 0;
        while (mini <= maxi)
        {
            int mid = (mini + maxi) >> 1;

            if (canarrange(x, mid, k))
            {
                ans = mid;

                mini = mid + 1;
            }
            else
                maxi = mid - 1;
        }
        cout << ans << "\n";
    }
}
