/// https://leetcode.com/problems/increasing-order-search-tree/
/// lc 987

#include <bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;

class Solution {
public:
     vector<int> x;
    TreeNode* increasingBST(TreeNode* root) {
       
        inorder(root);
        TreeNode* temp = new TreeNode(x[0]);
        TreeNode* vv = temp;
        for(int i=1;i<x.size();i++)
        {
            TreeNode * t  = new TreeNode(x[i]);
            vv ->right = t; 
            vv = vv->right;
        }
        return temp;
        
    }
   void inorder(TreeNode* root)
   {
       if(root==NULL)
           return;
       inorder(root->left);
       x.push_back(root->val);
       inorder(root->right);
   }
};