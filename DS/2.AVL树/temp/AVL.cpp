/*************************************************************************
	> File Name: AVL.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  1/ 1 19:47:32 2021
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

#define L(n) (n ? n->lchild : NULL)
#define R(n) (n ? n->rchild : NULL)
#define H(n) (n->h)
typedef struct Node {
    int key;
    int h; //高度
    struct Node *lchild,*rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NULL;
    return p;
}
void clear(Node *root) {
    if(root == NULL)
        return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}

void update_heigh(Node *root){
    root->h = H(L(root)) > H(R(root)) ? H(L(root)) + 1 : H(R(root)) + 1;
}
Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key)
        root->lchild = insert(root->lchild, key);
    else 
        root->rchild = insert(root->rchild,key);
    update_heigh(root);
    return root;
}


//找前驱
Node *predecessor(Node *root) {
    Node* temp = root->lchild;
    //左节点的最右节点
    while(temp->rchild) temp = temp->rchild;
    return temp;
}
Node *erase(Node *root, int key){
    if ( root == NULL) return NULL;
    if (key < root->key) 
        root->lchild = erase(root->lchild,key);
    else if(key > root->key)
        root->rchild = erase(root->rchild,key);
    else {
        // 叶子节点 或者 度为1
        if(root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root); // 找前驱
            root->key = temp->key; //覆盖当前值
            root->lchild = erase(root->lchild,root->key); //从左子树删除重复节点
        }
        
    }
    update_heigh(root);
    return root;
}
int main() {
     return 1;
}
