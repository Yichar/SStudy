#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <math.h>

#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define H(n) (n->h)

typedef struct Node {
    int key;
    int h;
    struct Node *lchild, *rchild;

} Node;


//虚拟空节点,可以访问
Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return;
}
Node* getNewNode(int key) {
    Node *root = (Node *)malloc(sizeof(Node));
    root->key = key;
    //初试高度为1
    root->h = 1;
    root->lchild = root->rchild = NIL;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}
void update_height(Node *root) {
    root->h = H(L(root)) > H(R(root)) ? (H(L(root))  + 1) : (H(R(root)) + 1);
    return;
}

Node *left_rotate(Node *root) {
    Node *newroot = root->rchild;
    root->rchild = newroot->lchild;
    newroot->lchild = root;
    update_height(root);
    update_height(newroot);
    return newroot;
}

Node *right_rotate(Node *root) {
    Node *newroot = root->lchild;
    root->lchild = newroot->rchild;
    newroot->rchild = root;
    update_height(root);
    update_height(newroot);
    return newroot;
}

Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    if (root->lchild->h > root->rchild->h) {
        //小左旋
        if (root->lchild->lchild->h < root->lchild->rchild->h)
            root->lchild = left_rotate(root->lchild);
        //大右旋
        root = right_rotate(root);
    } else {
        //x小右旋
        if (root->rchild->lchild > root->rchild->rchild) 
            root->rchild = right_rotate(root->rchild);
        root = left_rotate(root);
    }
    return root;
}


Node *insert(Node *root,int val) {
    if (root == NIL)  return getNewNode(val);
    if (root->key == val) return root;
    if (val < root->key)
        root->lchild = insert(root->lchild,val);
    else
        root->rchild = insert(root->rchild,val);
    update_height(root);
    return maintain(root);
}



Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root,int val) {
    if (root == NIL) return NIL;
    if (val < root->key) 
        root->lchild = erase(root->lchild,val);
    else if (val > root->key)
        root->rchild = erase(root->rchild,val);
    //找到了，讨论度为0，1，2
    else {
        if (root->lchild == NIL|| root->rchild == NIL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild,val);
        }
    }
    update_height(root);
    return maintain(root);

}


void print(Node *root) {
    printf("%d[%d] %d %d \n",
            root->key,root->h,root->lchild->key,root->rchild->key);
}
void output(Node *root) {
    if (root == NIL) return;
    print(root);
    output(root->lchild);
    output(root->rchild);
}


int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 0: root = erase(root, val); break;
            case 1: root = insert(root, val); break;
        }
        output(root);
        printf("------------\n");
    }
    return 0;
}