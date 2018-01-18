/*
637. Average of Levels in Binary Tree

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector <TreeNode*> nextl, current = {root};
        double summ;
        while (current.size() > 0){
            for(auto node: current){
                summ += node->val;
                if (node->left)
                    nextl.push_back(node->left);
                
                if (node->right)
                    nextl.push_back(node->right);
            }
            
            result.push_back(summ/double(current.size()));
            current.clear();
            current = nextl;
            nextl.clear();
            summ = 0;
        }
        
        return result;
    }
};