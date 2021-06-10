
// https://leetcode.com/problems/rotate-list/
// lc 61 Medium

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
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == NULL || head->next == NULL || k == 0)
            return head;

        ListNode *temp = head;

        int n = 1;
        while (temp->next != NULL)
        {
            temp = temp->next;
            n++;
        }
        temp->next = head;

        n = n - k % n;
        while (n--)
        {
            temp = temp->next;
        }

        head = temp->next;
        temp->next = NULL;
        return head;
    }
};