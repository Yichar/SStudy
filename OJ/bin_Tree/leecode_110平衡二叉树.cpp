class Solution {
public:
    int getdeep(TreeNode *node){
        if(node == nullptr)
            return 0;
        int dl = getdeep(node->left);
        int dr = getdeep(node->right);
        return max(dl,dr) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
      
        return abs(getdeep(root->right) - getdeep(root->left)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};