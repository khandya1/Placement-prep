// https://leetcode.com/problems/reverse-linked-list-ii/
// lc 92 Medium


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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0), *pre = dummy, *cur; // dsummy needed in case we have to start reversal from the first node
        dummy->next = head;
        for (int i = 0; i < left - 1; i++)
            pre = pre->next;

        ListNode *curr = pre->next;
        ;

        cout << pre->val;
        for (int i = left; i < right; i++)
        {

            ListNode *tt = pre->next;
            pre->next = curr->next;
            curr->next = curr->next->next;
            pre->next->next = tt;
        }
        return dummy->next;
    }
};