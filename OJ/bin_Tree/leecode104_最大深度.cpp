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
 //递归
class Solution {
public:
    int getDepth(TreeNode *root){
        if(root == nullptr)
            return 0;
        
        return 1 + max(getDepth(root->left),getDepth(root->right));
    }
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};

//迭代
class Solution {
public:
 
    queue<TreeNode *> Q;
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        Q.push(root);
        int ans = 0;
        while(!Q.empty()) {
            int size = Q.size();
            for(int i = 0; i < size; i++){
                TreeNode *temp = Q.front();
                Q.pop();
           
                if( temp->left != nullptr)
                    Q.push(temp->left);
                if(temp->right != nullptr)
                    Q.push(temp->right);
            } 
            ans++;
        }
        return ans;
    }
};