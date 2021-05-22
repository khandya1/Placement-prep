#include<bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
        
        
        vector<vector<int>> level;
        if(root==NULL)
            return level;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> x;
            int size=q.size();
            while(size--)
            {
                TreeNode* front = q.front();
                q.pop();
                x.push_back(front->val);
                if(front->left!=NULL) q.push(front->left);
                if(front->right!=NULL) q.push(front->right);
                
             }
            level.push_back(x);
            x.clear();
        }
        return level;
        
    }


