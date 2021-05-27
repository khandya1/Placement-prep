
//// https://leetcode.com/problems/deepest-leaves-sum/
//// lc 1302 Medium

#include <bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;


class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        int sum =0;
        q.push(root);
        while(!q.empty())
        {
            sum =0;
            int size = q.size();
            while(size--)
            {
               TreeNode* temp = q.front();
                 sum+= temp->val;
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
        }
        return sum;
    }




    /////////////////////////////
    //recurrsive solution earlier approach , check how recurrsion works

    int get_depth(TreeNode* root){
        if(!root) return 0;
        return 1 + max(get_depth(root->left), get_depth(root->right));
    }
    int get_sum(TreeNode* root, int depth){
        if (!root) return 0;
        if (depth == 1) return root->val;
        return get_sum(root->left, depth-1) + get_sum(root->right, depth-1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int depth = get_depth(root);
        int sum = get_sum(root, depth);
        return sum;
    }
};
