////https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/?company[]=Walmart&company[]=Walmart&problemStatus=unsolved&problemType=functional&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&page=1&query=company[]WalmartproblemStatusunsolvedproblemTypefunctionaldifficulty[]-2difficulty[]-1difficulty[]0page1company[]Walmart#

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Node
    {
        int data;
        Node *left, *right;
    };
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sumTree(Node *node)
    {
        if (node == NULL)
            return 0;

        int val;

        val = node->data;

        node->data = sumTree(node->left) + sumTree(node->right);

        return node->data + val;
    }
};