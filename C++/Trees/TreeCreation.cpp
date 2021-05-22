// creating tree using array in level order fashion
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d)
    {
        val = d;
        left=NULL;
        right=NULL;
    }
    TreeNode *buildTree(TreeNode *root)
    {
        int d;
        cin>>d;
        if(d==-1)
        return NULL;
        TreeNode *root= new TreeNode(d);
        root->left=buildTree(root->left);
        root->right=buildTree(root->right);
        return root;
    }

    TreeNode *buildTreeLevelOrderfromArray(int arr[], TreeNode *root, int index, int size )
    {
        if(index<size)
        {
            TreeNode *temp = new TreeNode(arr[index]);
            root = temp;
            root->left = buildTreeLevelOrderfromArray(arr, root->left, 2*index+1, size);
            root->right = buildTreeLevelOrderfromArray(arr, root->right, 2*index+2, size);
        }
        return root;
    }

};
