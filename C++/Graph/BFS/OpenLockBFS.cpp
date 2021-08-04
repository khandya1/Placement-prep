// https://leetcode.com/problems/open-the-lock/
// lc 752 Medium
// the lock number will be from 0000 to 9999 , main point here is to switch character from 0->9 0-> and 9->0 9->8
// insert all the charcters to the queue, and since there will be large number of of string , 
// mainiting set of strings for visited to search in O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {

        set<string> dead_end(deadends.begin(), deadends.end());

        queue<string> q;
        set<string> visited;

        q.push("0000");
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                string top = q.front();
                q.pop();
                if (top == target)
                    return level;
                if (dead_end.count(top) || visited.count(top))
                    continue;
                visited.insert(top);
                for (int i = 0; i < 4; i++)
                {
                    string next_up = top;
                    next_up[i] = top[i] == '9' ? '0' : top[i] + 1;
                    q.push(next_up);
                    string next_down = top;
                    next_down[i] = top[i] == '0' ? '9' : top[i] - 1;
                    q.push(next_down);
                }
            }
            level++;
        }
        return -1;
    }
};