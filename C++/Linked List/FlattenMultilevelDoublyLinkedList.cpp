// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// lc 430 Medium

#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {

        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->child)
            {
                Node *node_child = temp->child;
                if (temp->next == NULL)
                {
                    temp->next = node_child;
                    node_child->prev = temp;
                    temp->child = NULL;
                    continue;
                }
                Node *next_node= temp->next; // this next node pointer is required to remove infinte loop
                

                temp->next = node_child;
                node_child->prev = temp;
                temp->child = NULL;
                while (node_child->next != NULL)
                {
                    node_child = node_child->next;
                }
                node_child->next = next_node;
                next_node->prev = node_child;
            }

            temp = temp->next;
        }
        return head;
    }
};