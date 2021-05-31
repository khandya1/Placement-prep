// https://leetcode.com/problems/leaf-similar-trees/

// LC 872
// Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
// Two binary trees are considered leaf-similar if their leaf value sequence is the same.

// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

// if string is used instead of vector it gives lower run time, adding "#" is required in case where there are null values,
// so 1#2#3 != 12##3 12and 3 are different than 1 2 3

#include<bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string x,y;
        findLeaves(root1,x);
        findLeaves(root2,y);
        if(x==y)
            return true;
        return false;        
    }
    void findLeaves(TreeNode* root , string &x)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            x+=to_string(root->val)+"#";
        findLeaves(root->left,x);
        findLeaves(root->right,x);
    }



    ///// stack solution checking node by node

    bool leafSimilarS(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1,s2;
        s1.push(root1);
        s2.push(root2);
        while(!s1.empty() && !s2.empty())
        {if(findLeaveSS(s1)!=findLeaveSS(s2))
            return false;  
            }
        return s1.empty() && s2.empty();
                       
    }
    int findLeaveSS(stack<TreeNode*> &s)
    {
       while(true)
       {
           TreeNode * t = s.top();
           s.pop();
           if(t->right) s.push(t->right);
           if(t->left)  s.push(t->left);
           if(!t->right && !t->left) return t->val;
       }
    }
};