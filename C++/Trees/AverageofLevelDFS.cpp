///   https://leetcode.com/problems/average-of-levels-in-binary-tree 
///leetcode 637

#include<bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;


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
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<int> counts;
        vector<double> avgs;
        average(root, counts, avgs, 0);
        for (int i = 0; i < avgs.size(); i++) {
            avgs[i] /= counts[i];
        }
        return avgs;
    }
private:
    void average(TreeNode* root, vector<int>& counts, vector<double>& sums, int l) {
        if (!root) {
            return;
        }
        if (counts.size() <= l) {
            counts.push_back({});/// just increasing the size, default value becomes 0
        }
        if (sums.size() <= l) {
            sums.push_back({});
        }
        counts[l]++;// count of elements in level, incase the value of l is same , no of elements will increase
      
        sums[l] += root -> val;
        average(root -> left, counts, sums, l + 1);
        average(root -> right, counts, sums, l + 1);        
    }
};