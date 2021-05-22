#include<bits/stdc++.h>
#include "TreeCreation.cpp"

using namespace std;
    vector<int> x;
    vector<int> Traversal(TreeNode* root) {
        
        inorderT(root);
        preorderT(root);
        postorderT(root);   
        return x;
    }
                 
    void inorderT(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorderT(root->left);
        x.push_back(root->val);
        inorderT(root->right);
    }
    void preorderT(TreeNode* root)
    {
        if(root==NULL)
            return;
        x.push_back(root->val);
        preorderT(root->left);
        preorderT(root->right);
    }
    void postorderT(TreeNode* root)
    {
        if(root==NULL)
            return;
        postorderT(root->left);
        postorderT(root->right);
        x.push_back(root->val);
    }