//  cartesian tree is one where the root node is greater than child nodes
//  so we first find the greatest node in the vector and make it root, then for left, we will 
//  find the nodes from start to max , taking account that this traversal is inorder traversal and 
//  middle one is treated as root



#include <bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;

class solution
{
    int findmax(vector<int> &A, int start, int end)
    {
        int max = A[start];
        int index = start;
        for (int i = start; i <= end; i++)
        {
            if (max < A[i])
            {
                max = A[i];
                index = i;
            }
        }
        return index;
    }
    TreeNode *makeCart(vector<int> &A, int start, int end)
    {
        if (start > end)
            return NULL;
        int max = findmax(A, start, end);
        TreeNode *node = new TreeNode(A[max]);
        node->left = makeCart(A, start, max - 1);
        node->right = makeCart(A, max + 1, end);

        return node;
    }
    TreeNode *buildTree(vector<int> &A)
    {

        return makeCart(A, 0, A.size() - 1);
    }
};