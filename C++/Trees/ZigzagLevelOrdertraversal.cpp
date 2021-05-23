//// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

//// lc 103


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        
        vector<vector<int>> level;
        if(root==NULL)
            return level;
        stack<TreeNode*> s1,s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty())
        {
            vector<int> x,y;
            while(!s1.empty())
            {
                TreeNode* f= s1.top();
                s1.pop();
                x.push_back(f->val);
                if(f->left)  s2.push(f->left);
                if(f->right) s2.push(f->right);
            }
            if(!x.empty())
            level.push_back(x);
            x.clear();
            while(!s2.empty())
            {
                TreeNode* f= s2.top();
                s2.pop();
                y.push_back(f->val);
                if(f->right)  s1.push(f->right);
                if(f->left) s1.push(f->left);
            }
            if(!y.empty())
            level.push_back(y);
            y.clear();
            
        }
        return level;
        
    }
};