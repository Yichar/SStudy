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
    struct Node *lchild,*rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->h = 0;
    NIL->key = 0;
    NIL->lchild = NIL->rchild = NIL;
}

void update_height(Node *root) {
   root->h = H(L(root)) > H(R(root)) ? H(L(root)) + 1 : H(R(root)) + 1;
   return;
}


Node *getNewNode(int val) {
    Node *root = (Node*)malloc(sizeof(Node));
    root->h = 0;
    root->key = val;
    root->rchild = root->lchild = NIL;
    return root;
}
Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}
Node *maintan1(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    if (root->lchild->h > root->rchild->h) {
        if (root->lchild->lchild->h < root->lchild->rchild->h) 
            root->lchild = left_rotate(root->lchild);
        root = right_rotate(root);
    } else {
        if (root->rchild->rchild->h < root->rchild->lchild->h) 
            root->rchild = right_rotate(root->rchild);
        root = left_rotate(root);
    }
    return root;
}

Node *maintan(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    //LR LL
    if (root->lchild->h > root->rchild->h) {
        if (root->lchild->lchild->h < root->lchild->rchild->h)
            root->lchild = left_rotate(root->lchild);
        root = right_rotate(root);
    } else {
         if (root->rchild->rchild->h < root->rchild->lchild->h)
            root->rchild = right_rotate(root->rchild);
        root = left_rotate(root);
    }
    return root;
}
Node *precessor(Node *root) {
    Node *temp = root->lchild;
    while(temp->rchild) temp = temp->rchild;
    return temp;
}
Node *insert(Node *root, int val)  {
    if (root == NIL) return getNewNode(val);
    if (root->key == val) return root;
    if (val < root->key) {
        root->lchild = insert(root->lchild,val);
    } else {
        root->rchild = insert(root->rchild,val);
    }
    update_height(root);
    return maintan(root);
}

Node *erase(Node *root,int val) {
    if (root == NIL) return NIL;
    if (val < root->key) {
        root->lchild = erase(root->lchild,val); 
    } else if (val > root->key) {
        root->rchild = erase(root->rchild,val);
    } else {
        if (root->rchild == NIL || root->lchild == NIL) {
            Node *temp = root->rchild ? root->rchild : root->lchild;
            free(root);
            return temp;
        } else {
            Node *temp = precessor(root);
            root->key = temp->key;
            erase(root->lchild,temp->key);
        }
    }
    update_height(root);
    return maintan(root);
}

void output(Node *root) {
    if (root == NIL) return;
    printf("%d[%d] %d %d\n",root->key,root->h,root->lchild->key,root->rchild->key);
    output(root->lchild);
    output(root->rchild);
    return;
}

void clear(Node *root) {
    if (root == NIL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
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