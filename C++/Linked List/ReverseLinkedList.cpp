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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL)
        {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* reverseListrec(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};