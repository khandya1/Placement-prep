// https://leetcode.com/problems/odd-even-linked-list/
// lc 328
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
    ListNode *oddEvenList(ListNode *head)
    {

        if (head == NULL)
            return head;
        ListNode *odd = head;
        ListNode *evenhead = head->next;
        ListNode *even = evenhead;

        while (even != NULL && even->next != NULL)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};