// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// lc 82 Medium


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
    ListNode *deleteDuplicates(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *temp = pre;
        int flag = 0;
        cout << pre->next->val;
        while (head)
        {

            if (head->next && (head->val == head->next->val))
            {

                while (head->next && (head->val == head->next->val))
                {
                    head = head->next;
                }

                pre->next = head->next;
            }
            else
                pre = pre->next;

            head = head->next;
        }
        return temp->next;
    }
};