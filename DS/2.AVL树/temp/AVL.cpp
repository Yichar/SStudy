/*************************************************************************
	> File Name: AVL.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  1/ 1 19:47:32 2021
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define H(n) (n->h)
typedef struct Node {
    int key;
    int h; //高度
    struct Node *lchild,*rchild;
} Node;
//虚拟空节点，替代NULL
Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init__NIL() {
    NIL->key = 0, NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return;
}
//优先初始化上面这段代码



Node *maintain(Node *root);

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
}
void clear(Node *root) {
    if(root == NIL)
        return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}

void update_height(Node *root){
    root->h = H(L(root)) > H(R(root)) ? H(L(root)) + 1 : H(R(root)) + 1;
    return;
}
Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key)
        root->lchild = insert(root->lchild, key);
    else 
        root->rchild = insert(root->rchild,key);
    update_height(root);
    return maintain(root);
}


//找前驱
Node *predecessor(Node *root) {
    Node* temp = root->lchild;
    //左节点的最右节点
    while(temp->rchild) temp = temp->rchild;
    return temp;
}
//左旋 和右旋对称
Node *left_rotate(Node *root) {
    Node *temp = root->rchild; // 新根节点
    root->rchild = temp->lchild; //新左挂旧右
    temp->lchild = root; //旧根挂新左
    update_height(root);
    update_height(temp);
    return temp;
}
//右旋，记这个
Node *right_rotate(Node *root){
    Node *temp = root->lchild; // 新根
    root->lchild = temp->rchild; //新右成旧左
    temp->rchild = root; //旧根成新左
    update_height(root);
    update_height(temp);
    return temp;
}
//调整
Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
        if (root->lchild->h > root->rchild->h) {
            //LR先小左旋
            if(root->lchild->lchild->h < root->lchild->rchild->h)
                root->lchild = left_rotate(root->lchild);
            //LL 只需大右旋
            root = right_rotate(root);
        } else {
                //RL 先小右旋
                if (root->rchild->rchild->h < root->rchild->lchild->h)
                    root->rchild = right_rotate(root->rchild);
                //RR 大左旋
                root = left_rotate(root);
        }

        return root;
}
//删除
Node *erase(Node *root, int key){
    if ( root == NIL) return NIL;
    if (key < root->key) 
        root->lchild = erase(root->lchild,key);
    else if(key > root->key)
        root->rchild = erase(root->rchild,key);
    else {
        // 叶子节点 或者 度为1
        if(root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root); // 找前驱
            root->key = temp->key; //覆盖当前值
            root->lchild = erase(root->lchild,root->key); //从左子树删除重复节点
        }
        
    }
    update_height(root);
    return maintain(root);
}

void printf(Node *root) {
    printf("(%d[%d],%d,%d)\n",
           root->key,root->h,
           root->lchild->h,
           root->rchild->h
          );
    return;
}
void output(Node *root) {
    if(root == NIL) return;
    printf(root);
    output(root->lchild);
    output(root->rchild);
    return;
}
int main() {
     int op, val;
    Node *root = NIL;
    while (~scanf("%d%d",&op,&val)) {
        switch (op) {
            case 0: 
                root = erase(root, val);
                break;
            case 1:
                root = insert(root, val);
                break;
        }
        output(root);
    }
     return 1;
}
