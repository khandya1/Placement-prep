//// https://leetcode.com/problems/search-in-a-binary-search-tree/ 
// lc 700
//  in BST use the use the property of BST judiciously , the left subtree will always
//  contain nodes with value less than root's value and right subtree will 
//  contain nodes with value greater than root's value)


#include <bits/stdc++.h>
#include "TreeCreation.cpp"

using namespace std;
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {

        if (root == NULL || root->val == val)
            return root;
        return val < root->val ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};
