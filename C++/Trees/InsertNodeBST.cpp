//// https://leetcode.com/problems/insert-into-a-binary-search-tree/
// lc 701
//  in BST use the use the property of BST judiciously , the left subtree will always
//  contain nodes with value less than root's value and right subtree will 
//  contain nodes with value greater than root's value)


#include <bits/stdc++.h>
#include "TreeCreation.cpp"

using namespace std;
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            if (root->left) {
                insertIntoBST(root->left, val);
            } else {
                root->left = new TreeNode(val);
            }
        } else {
            if (root->right) {
                insertIntoBST(root->right, val);
            } else {
                root->right = new TreeNode(val);
            }
        }
        return root;
    }
};