 //前序  根左右
 void preorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
		res.push_back(root->val);  
        preorder(root->left, res);  
        preorder(root->right, res);
  }
//中序 左根右
void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);  
        res.push_back(root->val);  
        inorder(root->right, res);
  }

  //后序 左右根
   void postorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        postorder(root->left, res);  
        postorder(root->right, res);
		res.push_back(root->val);  
  }
  
  
  //非递归 前序  非空则入栈，取值再取左，若空则出栈，再取右节点
  
vector<int> ans;
stack<TreeNode *> S;
while( root != nullptr || !S.empty()) {
    if( root != nullptr){
        S.push(root); //存起来
		ans.push_back(root->val);  //取值
        root = root->left; //取左节点
    } else {
        TreeNode temp = S.top(); //拿出来
        S.pop();
        root = temp->right;  // 取右节点
    }
}
return ans;

// 非递归 中序 非空则入栈，先取左节点，若空则出栈，取值再取右。

 vector<int> ans;
stack<TreeNode*> S;
while(root != nullptr || !S.empty()){
	if(root != nullptr) {
		S.push(root);
		root = root->left;
	} else {
		TreeNode *node = S.top();
		S.pop();
		ans.push_back(node->val);
		root = node->right;
	}
}
return ans;
		
// 非递归 后序 	 非空则入栈，插头后取右，若空则出栈，再取左节点。

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> S;
        while(root != nullptr || !S.empty()) {
			if(root != nullptr) {
				S.push(root);
				ans.insert(ans.begin(),root->val);
				root=root->right;
			} else {
				TreeNode *node = S.top();
				S.pop();
				root = node->left;
			}
		}
		return ans;
	}
