#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};

class MyLinkedList
{
public:
    /** Initialize your data structure here. */
    int len = 0;
    Node *head = NULL;

    MyLinkedList()
    {
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {

        if (index >= len || index < 0)
            return -1;
        Node *curr = head;
        while (index > 0)
        {
            index--;
            curr = curr->next;
        }

        return curr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {

        Node *temp = new Node(val);
        if (head == NULL)
            head = temp;

        else
        {
            temp->next = head;
            head = temp;
        }
        len++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {

        Node *temp = new Node(val);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            Node *curr = head;
            while (curr->next != NULL)
                curr = curr->next;

            curr->next = temp;
        }
        len++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > len)
            return;

        if (index == 0)
            addAtHead(val);

        else if (index == len)
            addAtTail(val);

        else
        {
            Node *curr = head;
            while (index > 1)
            {
                curr = curr->next;
                index--;
            }
            cout << curr->val << "kk";
            Node *temp = new Node(val);
            temp->next = curr->next;
            curr->next = temp;
            len++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index >= len)
            return;
        if (index == 0)
        {
            this->head = this->head->next;
            return;
        }
        if (index == len - 1)
        {
            Node *curr = head;
            index = index - 1;
            while (index--)
                curr = curr->next;
            curr->next = curr->next->next;
            len--;
            return;
        }

        Node *curr = head;
        index = index - 1;
        while (index--)
        {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        len--;
    }
};
