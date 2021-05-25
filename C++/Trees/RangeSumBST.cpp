///// https://leetcode.com/problems/range-sum-of-bst/
/// lc 938


#include<bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(root==NULL)
           return 0;
        else if(low<=root->val && root->val<=high)
           return root->val + rangeSumBST(root->left, low, high)+rangeSumBST(root->right, low, high);
         else if(root->val<low)
             return rangeSumBST(root->right, low, high);
         else 
             return rangeSumBST(root->left, low, high);
       
        
    }
};