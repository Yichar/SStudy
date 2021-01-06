/*************************************************************************
	> File Name: RB_Tree.c
	> Author: Yichar
	> Mail: 
	> Created Time: 一  1/ 4 17:56:19 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
    int key;
    int color; //0 red, 1 black, 2 double black;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL(){
    NIL->key = 0;
    NIL->color = 1; //叶节点默认为黑
    NIL->lchild = NIL->rchild = NIL;
    return ;
}
Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->color = 0;
    p->lchild = p->rchild = NIL;
    return p;
}

void clear(Node *root){
    if(root == NIL) return;
    clear(root->lchild);
    clear(root->rchild);
    return;
}

int has_red_child(Node *root){
    return root->lchild->color == 0 || root->rchild->color == 0;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}
//插入调整
Node *insert_maintan(Node *root) {
    if( !has_red_child(root)) return root; //无红色
    //root为黑
    //插入情况一 偷个懒
    if(root->lchild->color == 0 && root->rchild->color == 0) {
        root->color = 0;  //改成红黑黑
        root->lchild->color = root->rchild->color = 1; 
    }
    int flag = 0;
    if (root->lchild->color == 0 && has_red_child(root->lchild)) flag = 1;
    if (root->rchild->color == 0 && has_red_child(root->rchild)) flag = 2;
    if (flag == 0) 
        return root;
    if (flag == 1) { //LR LL
        if (root->lchild->rchild->color == 0) 
            root->lchild = left_rotate(root->lchild);
        root = right_rotate(root);
        //小帽子改成红嘿嘿
        root->color = 0;
        root->lchild->color = root->rchild->color = 1;
    } else { // RL RR
        if(root->rchild->lchild->color == 0) 
            root->rchild = right_rotate(root->rchild);
        root = left_rotate(root);
        root->color = 0;
        root->lchild->color = root->rchild->color = 1;
    }
    return root;
}

Node* __insert(Node *root, int key) {
    if(root == NIL) return getNewNode(key);
    if(root->key == key) return root;
    if(key < root->key) {
        root->lchild = __insert(root->lchild, key);
    } else {
        root->rchild = __insert(root->rchild, key);
    }
    return insert_maintan(root);
}
Node* insert(Node *root,int key){
    root = __insert(root,key);
    root->color = 1;
    return root;
}
void print(Node *root) {
    printf("%d[%d], %d, %d\n",
           root->color,root->key,
           
           root->lchild->key,root->rchild->key);
    return;
}


void output(Node *root) {
    if(root == NIL) return;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return;
}


int main() {
    int op, val;
    Node *root = NIL;
    printf("颜色，值，左值，右值\n");
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: 
                root = insert(root,val);
                break;
            
        }
    output(root);
    }
    return 0;
}
