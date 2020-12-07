class Solution {
public:
   
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode *> Q;
        Q.push(root->left);
        Q.push(root->right);
        while(!Q.empty()){
            TreeNode *left = Q.front();Q.pop();
            TreeNode *right = Q.front();Q.pop();
            if(left == NULL && right== NULL)
                continue;
            if(left == NULL || right == NULL || (left->val != right->val)) 
                return false;

            Q.push(left->left);
             Q.push(right->right);
            Q.push(left->right);
           
            Q.push(right->left);
          

        }
        return true;
    }
};
