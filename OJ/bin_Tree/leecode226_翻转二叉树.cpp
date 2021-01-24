/*************************************************************************
	> File Name: leecode226_翻转二叉树.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 日  1/24 13:14:35 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


//层序
class Solution {
public:
    queue<TreeNode *> Q; 
    TreeNode* invertTree(TreeNode* root) {
     if (root == nullptr) return root;   
     Q.push(root);
     while( !Q.empty()) {
         for(int i =0; i < Q.size(); i++) {
            TreeNode *temp = Q.front();
            Q.pop();
            if (temp->left || temp->right) {
                swap(temp->left,temp->right);
                if(temp->left) 
                    Q.push(temp->left);
                if(temp->right) 
                    Q.push(temp->right);
            }
         }
     }
     return root;
    }
};


//递归
class Solution {
public:
    void ReverseTree(TreeNode *root) {
        if (root == nullptr) return;
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right); 
    }
    TreeNode* invertTree(TreeNode* root) {
        
        ReverseTree(root);
        return root;
    }
};
