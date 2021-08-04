
#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &nums)
{
    vector<int> x = nums;
    sort(x.begin(), x.end());
    int sum = 0, c;
    vector<bool> visited(nums.size(), false); // checking if the array element is visited
    for (int i = 0; i < nums.size(); i++)
    {
        if (visited[i] == true || x[i] == nums[i]) // if already at it's place continue
            continue;

        else
        {
            int j = i;
            c = 0;
            while (!visited[j])
            {
                //  cout<<nums[j];
                visited[j] = true;
                c++;
                j = lower_bound(x.begin(), x.end(), nums[j]) - x.begin();
                //   cout<<j;
            }
            if (c > 0)
                sum += (c - 1);
        }
    }
    return sum;
}