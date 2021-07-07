


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {//// in binary search tree
        
        if(p->val <q->val)
            return lca (root, p, q);
        else
            return lca(root , q, p);
        
    }
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL || root==p || root==q)
            return root;
        
        
            if(p->val < root->val && q->val < root->val)
                return lca(root->left, p, q);
       
            else if(p->val > root->val && q->val > root->val)
                return lca(root->right, p, q);
            
            else
                 return root;
        
    }


    TreeNode* lowestCommonAncestorBT(TreeNode* root, TreeNode* p, TreeNode* q) {// in binary treee
        
        if(root==NULL || root==p || root==q)
            return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if(l!=NULL && r!=NULL)
            return root;
        
        else
            return (l!=NULL)? l : r;
        
    }
    
};