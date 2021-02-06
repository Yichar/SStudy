#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <math.h>

typedef struct Node {
    int key;
    int color; // 0 red, 1 black, 2 double black
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->color = 1;
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
Node *insert_maintain1(Node *root) {
    if (!has_red_child(root)) return root;
    int flag = 0;
    if (root->lchild->color == 0 && root->rchild->color == 0) goto insert_end;
    if (root->lchild->color == 0 && has_red_child(root->lchild)) flag = 1;
    if (root->rchild->color == 0 && has_red_child(root->rchild)) flag = 2;
    if (flag == 0) return root;
    if (flag == 1) {
        if (root->lchild->rchild->color == 0) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (root->rchild->lchild->color == 0) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
insert_end:
    root->color = 0;
    root->lchild->color = root->rchild->color = 1;
    return root;
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
    } else {
        if (root->rchild->lchild->color == 0)
            root->rchild = right_rotate(root->rchild);
        root = left_rotate(root);
    }
    insert_end:
        root->color = 0;
        root->lchild->color = root->rchild->color = 1;
        return root;
}
Node *__insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key) {
        root->lchild = __insert(root->lchild, key);
    } else {
        root->rchild = __insert(root->rchild, key);
    }
    return insert_maintain(root);
}


Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}
Node *erase_maintain(Node *root) {
    // 子节点无双重黑
    if (root->lchild->color != 2 && root->rchild->color != 2) return root;
    // 情况三：双重黑兄弟为红色，先旋转一次。旧根改红，新根改黑。
    if (has_red_child(root)) {
        int flag = 0;
        root->color = 0; //旧根改红
        if (root->lchild->color == 0) {
            root = right_rotate(root);
            flag = 1;
        }
        else {
            root = left_rotate(root);
            flag = 2;
        }
        
        root->color = 1; //新根改黑。
        //递归处理
        if (flag == 1) root->rchild = erase_maintain(root->rchild);
        else root->lchild = erase_maintain(root->lchild);
        return root;
        }
    // 情况1：双重黑兄弟 的子节点均为黑
    if (root->lchild->color == 2 && !has_red_child(root->rchild) ||
        root->rchild->color == 2 && !has_red_child(root->lchild)) {
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            root->color += 1;
            return root;
        }
    //情况2： 双重黑兄弟的子节点存在红
    if (root->lchild->color == 2) {
        //右兄弟的右子节点 如果不是红，就是RL类型
        if (root->rchild->rchild->color != 0) {
            root->rchild->color = 0;
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = 1;
        }
        // RR类型 
        root = left_rotate(root);
        root->color = root->lchild->color;
    } else {
        //左兄弟的左子节点，若不是红，就是LR类型
        if (root->lchild->lchild->color != 0) {
            root->lchild->color = 0;
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = 1;
        }
        // LL类型
        root = right_rotate(root);
        root->color = root->rchild->color;
    }
    root->lchild->color = root->rchild->color = 1;
    return root;

}

Node *__erase(Node *root,int key) {
    if (root== NIL) return NIL;
    if (key < root->key) 
        root->lchild = __erase(root->lchild, key);
    else if (key > root->key)
        root->rchild = __erase(root->rchild, key);
    else {
        //度位0，度为1的情况。将子节点的黑色加到唯一子孩子（由此可能产生双重黑）
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            temp->color += root->color;
            free(root);
            return temp;
        } else { //度为2 分情况讨论：
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}


Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = 1;
    return root;
}



Node *erase(Node *root, int key) {
    root = __erase(root, key);
    root->color = 1;
    return root;
}
void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void print(Node *root) {
    printf("(%d| %d, %d, %d)\n",
        root->color, root->key,
        root->lchild->key,
        root->rchild->key
    );
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return ;
}
int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
        }
        output(root);
        printf("------------\n");
    }
    return 0;
}