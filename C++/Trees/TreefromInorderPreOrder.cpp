// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// lc 105 Medium

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    unordered_map<int, int> M;
    int preIndex = 0;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            M[inorder[i]] = i;
        return btreeHelper(preorder, 0, inorder.size() - 1);
    }
    TreeNode *btreeHelper(vector<int> &preorder, int left, int right)
    {
        if (left > right)
            return NULL;
        int rootval = preorder[preIndex++];
        TreeNode *root = new TreeNode(rootval);

        root->left = btreeHelper(preorder, left, M[rootval] - 1);
        root->right = btreeHelper(preorder, M[rootval] + 1, right);

        return root;
    }
};