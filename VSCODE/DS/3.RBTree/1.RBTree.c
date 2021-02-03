#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <math.h>

typedef struct Node {
    int key;
    int color; // 0  red 1 black 2 double black
    struct Node *lchild, *rchild;
} Node;


Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->color = 1;
    NIL->lchild = NIL->rchild = NIL;
    return;
}


Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->color = 1;
    p->lchild->rchild = NIL;
    return p;
}

int has_red_child(Node *root) {
    return root->lchild->color == 0 || root->rchild->color == 0;
}


Node *left_rotate(Node *root) {
    Node *newroot = root->rchild;
    root->rchild = newroot->lchild;
    newroot->lchild = root;
    return newroot;
}


Node *right_rotate(Node *root) {
    Node *newroot = root->lchild;
    root->lchild = newroot->rchild;
    newroot->rchild = root;
    return newroot;
}
Node *insert_maintain(Node *root) {
    //左右孩子无红色节点，无需调整。
    if(!has_red_child(root)) return root; 
    //此时root必然为黑色，否则会提前冲突。

    int flag = 0;
    //只要发现左右节点均为红色，就改成红黑黑(不一定冲突，但是可以直接调整，偷个懒)
    if (root->lchild->color == 0 && root->rchild->color == 0) {
        goto insert_end;
    }
    
    if (root->lchild->color == 0 && has_red_child(root->lchild)) 
        flag = 1; //LL，LR
    if (root->rchild->color == 0 && has_red_child(root->rchild))
        flag = 2; //RR,RL
    if (flag == 0) return root;
    if (flag == 1) {
        //如果是LR的情况，先小右旋
        if (root->lchild->rchild->color == 0)
            root->lchild = left_rotate(root->lchild);
        root = right_rotate(root);
        root->color = 0;
        root->lchild->color = root->rchild->color = 1;
    } else {
        if (root->rchild->lchild->color == 0)
            root->rchild = right_rotate(root->rchild);
    }
    insert_end:
        root = left_rotate(root);
        root->color = 0;
        root->lchild->color = root->rchild->color = 1;
        return root;
}
Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (key == root->key) return root;
    if (key < root->key) root->lchild = insert(root->lchild,key);
    else root->rchild = insert(root->rchild,key);
    return insert_maintain(root);
}
void clear(Node *root) {
    if (root == NIL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}


void print(Node *root) {
    printf("(%d| %d %d %d)\n",
        root->color,root->key,
        root->lchild->key,root->rchild->key);
    return;
}
void output(Node *root) {
    if (root == NIL) return;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return;
}
int main()
{   
    int op,val;
    Node *root = NIL;
    while(~scanf("%d%d",&op,&val)) {
        switch (op)
        {
        case 1:root = insert(root,val);
            break;
        
        default:
            break;
        }
        output(root);
    }
   return 0;
}
