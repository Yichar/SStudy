#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <math.h>

#define KEY(a) (a ? a->key : 0)
#define SIZE(n) (n ? n->size : 0)
#define L(n) (n ? n->lchild : NULL)

typedef struct Node {
    int key;
    int size;
    struct Node *lchild, *rchild;
} Node;


Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->size = 1;
    p->lchild = p->rchild = NULL;
    return p;
}
Node *predecessor(Node *root) {
    //左子树中的最大值。
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}
void update_size(Node *root) {
    root->size = (SIZE(root->lchild)) + (SIZE(root->rchild)) + 1;    
}
//查找排名第K的元素
int search_k(Node *root,int k) {
    if (root == NULL) return -1;
    if ( SIZE(L(root)) == k - 1) return root->key;
    if (k <= SIZE(L(root))) return search_k(root->lchild,k);
    else return search_k(root->rchild,k - SIZE(L(root)) - 1);
}
int search(int val,Node *root) {
    if (root == NULL) return 0;
    if (val == root->key) return 1;
    else if (val < root->key) search(val,root->lchild);
    else  search(val,root->rchild);
    return 0;
}
Node * insert(Node *root,int key) {
    if (root == NULL) {
        return getNewNode(key);
    }
    if (root->key == key) return root;
    if (key < root->key) root->lchild = insert(root->lchild,key);
    else root->rchild = insert(root->rchild,key);
    update_size(root);
    return root;
}



Node *erase(Node *root,int key) {
    if (root == NULL) return root;
    if (key < root->key) 
        root->lchild = erase(root->lchild, key);
    else if (key > root->key)
        root->rchild = erase(root->rchild, key);
    //找到待删除的节点
    else {
        //度为0，直接free该节点（可以被优化）
        if (root->rchild == NULL && root->lchild == NULL) {
            free(root);
            return NULL;
        //度为1，用子节点替换该节点 （也可以处理度为0情况）
        } else if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        //度为2，找该节点的前驱或后继，将其值覆盖该节点的值，然后删除前驱节点。由此转化为前2种情况
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key; //覆盖
            root->lchild = erase(root->lchild,temp->key); //转化为在左子树删除前驱节点的值

        }

    }
    update_size(root);
    return root;
    
}

void clear(Node *node) {
    if (node == NULL)
        return;
    clear(node->rchild);
    clear(node->lchild);
    return;
}

void print(Node *root) {
   printf("(%d[%d] : %d %d)\n",
           KEY(root),root->size,KEY(root->lchild),KEY(root->rchild)); 

    
}

void output(Node *root) {
    if (root == NULL)
        return;
    output(root->lchild);
    printf("(%d[%d] : %d %d)\n",KEY(root),root->size,KEY(root->lchild),KEY(root->rchild));
    output(root->rchild);
}



void output_k(Node *root,int k) {
    if ( k == 0 || root == NULL) return;
    //左子树更多
    if (k <= SIZE(L(root)))
        output_k(root->lchild, k);
    else {
        output(root->lchild);
        print(root);
        output_k(root->rchild,k - SIZE(L(root)) - 1);
    }
}


int main()
{
    Node *root = NULL;
   int op, val;
   while (~scanf("%d%d", &op, &val)) {
       switch (op) {
           case 0: printf("search %d, result : %d \n",val,search(val,root));break;
           case 1: root = insert(root,val);break;
           case 2: root = erase(root,val);break;
           case 3: printf("search k = %d , result : %d \n",val,search_k(root,val));break;
           case 4: output_k(root,val);break;
       }
       if (op == 1 || op == 2) {
           output(root);
           printf("-----------\n");
       }
   }
   return 0;
}
