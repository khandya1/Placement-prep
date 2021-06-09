// https://leetcode.com/problems/next-greater-node-in-linked-list/
// lc 1019 Medium 
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    vector<int> nextLargerNodes(ListNode *head)
    {

        vector<int> ans;
        stack<pair<int, int>> s;
        int i = 0;
        while (head)
        {
            while (!s.empty() && s.top().first < head->val)
            {

                ans[s.top().second] = head->val; // till there is low number on node 
                s.pop();
            }
            s.push({head->val, i++});
            head = head->next;
            ans.push_back(0);
        }
        return ans;
    }
};