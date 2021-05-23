/////   https://leetcode.com/problems/minimum-depth-of-binary-tree/
//// lc 111

#include <bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;
class Solution
{
public:
    int minDepthDFS(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;

        int left = (root->left ? minDepthDFS(root->left) : INT_MAX);
        int right = (root->right ? minDepthDFS(root->right) : INT_MAX);

        return 1 + min(left, right);
    }

    int minDepthBFS(TreeNode *root)
    {
        if (!root)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        int depth = 1;

        while (!q.empty())
        {
            int level_size = q.size();
            for (int i = 0; i < level_size; i++)
            {
                TreeNode *curr_node = q.front();
                q.pop();
                if (!curr_node->left && !curr_node->right)
                    return depth; // first leaf we reach

                if (curr_node->left)
                    q.push(curr_node->left);
                if (curr_node->right)
                    q.push(curr_node->right);
            }

            depth++;
        }

        return depth;
    }

    int minDepthSol(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int l = minDepthSol(root->left), r = minDepthSol(root->right);
        return 1 + (min(l, r) ? min(l, r) : max(l, r));
    }
};