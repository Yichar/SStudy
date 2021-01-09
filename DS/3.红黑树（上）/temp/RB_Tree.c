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


Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;

}

Node *erase_maintain(Node *root) {
    //无双重黑，不用调整
    if (root->lchild->color != 2 && root->rchild->color != 2) 
        return root;
    //情况三： 子节：双重黑  + 红色 -> 情况一和二 子节点为双重黑 + 黑  
    if (has_red_child(root)) {
        int flag = 0;
        //原根改红
        root->color = 0;
        //左子树是红 小右旋
        if (root->lchild->color == 0) {
            root = right_rotate(root);
            flag = 1;
        //右子树为红 小左旋
        } else {
            root = left_rotate(root);
            flag = 2;
        }
        //新根改黑
        root->color = 1;
        //左旋递归左树，右旋递归右树
        if (flag == 1) root->rchild = erase_maintain(root->rchild);
        else root->lchild = erase_maintain(root->lchild);
    }
    //情况一：子节点：双重黑 + 黑<黑，黑>
    if ((root->lchild->color == 2  &&  !has_red_child(root->rchild)) ||
        root->rchild->color == 2 && !has_red_child(root->lchild) ) {
        // 父节点加，子节点减
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            root->color += 1;
            return root;
    }
    //情况二： 子节点： 双重黑 + 黑<黑，红> 或者 黑<红，黑>
    if (root->lchild->color == 2) {
        //RL 小右旋 + 左旋
        if (root->rchild->rchild->color != 0) {
            root->rchild->color = 0;
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = 1;
        }
        //RR 左旋
        root = left_rotate(root);
        root->color = root->lchild->color;

    } else {
        //LR 小左旋 + 右旋
        if (root->lchild->lchild->color != 0) {
            root->lchild->color = 0;
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = 1;
        }
        //LL 右旋
        root = right_rotate(root);
        root->color = root->rchild->color;
    }
    return root;
}

Node *__erase(Node *root, int key) {
    if (root == NIL) return NIL;
    if (key < root->key) 
        root->lchild = __erase(root->lchild, key);
    else if (key > root->key)
        root->rchild = __erase(root->rchild, key);
    else {
        //度为0或者1，将该节点的颜色加到子节点上，然后用子节点替换之，；
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            //找前驱，转换为度为1的情况
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);

        }

    }

    return erase_maintain(root);

}

//删除双黑节点，变为黑色。
Node *erase(Node *root, int key) {
    root = __erase(root, key);
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
            case 2:
                root = erase(root,val);
                break;
            
        }
    output(root);
    }
    return 0;
}
