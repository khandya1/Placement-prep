// https://leetcode.com/problems/merge-k-sorted-lists/
// lc 23 hard
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq; /// creating a min heap
        for (auto i : lists)
        {
            if (i)
                pq.push({i->val, i});
        }
        ListNode *temp = new ListNode(0);
        ListNode *ptr = temp;
        while (!pq.empty())
        {
            int x = pq.top().first;
            ListNode *node = pq.top().second;
            ptr->next = pq.top().second;
            pq.pop();
            ptr = ptr->next;

            if (node->next)
            {
                node = node->next;
                pq.push({node->val, node});
            }
        }
        return temp->next;
    }
};