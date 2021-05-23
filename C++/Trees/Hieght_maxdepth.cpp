/////    https://leetcode.com/problems/maximum-depth-of-binary-tree
//// lc 104

#include<bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(root==NULL)
            return 0;
       
        
        int lr = maxDepth(root->left);
        int rr = maxDepth(root->right);
        
        return 1+max(lr,rr);
        
    }
};