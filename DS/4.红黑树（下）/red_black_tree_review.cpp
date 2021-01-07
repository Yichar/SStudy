/*************************************************************************
    > File Name: red_black_tree_review.cpp
    > Author: xiaocui
    > Mail: 1198016164@qq.com
    > Created Time: Tue 05 Jan 2021 01:27:04 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <math.h>

#define NIL     (&__NIL)
#define COLOR_HL(a, b)      "\033[1;" #b "m" a "\033[0m"
#define GREEN_HL(a)         COLOR_HL(a, 32)
#define RED_HL(a)           COLOR_HL(a, 31)
#define BLUE_HL(a)          COLOR_HL(a, 34)
#define YELLOW_HL(a)        COLOR_HL(a, 33)
#define PURPLE_HL(a)        COLOR_HL(a, 35)
#define BOTTLEGREEN_HL(a)   COLOR_HL(a, 36)
#define MOVETO(x,y)         printf("\033[%d;%dH", (x), (y)) // 定位光标
#define CLEAR()             printf("\033[2J") // 清除屏幕
typedef struct Node {
    int key, color;
    int h;      //添加一个高度用来计算显示的距离
    struct Node *lchild, *rchild;
} Node;

Node __NIL;

__attribute__((constructor)) void init_NIL() {
    NIL->color = 1;
    NIL->key = 0;
    NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

void update_height(Node *root) {
    root->h = ((root->lchild->h > root->rchild->h) ? (root->lchild->h) : (root->rchild->h)) + 1;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->color = 0;
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
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

int has_red_child(Node *root) {
    return root->lchild->color == 0 || root->rchild->color == 0;
}

Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;
    if ((root->lchild->color == 0 && has_red_child(root->lchild)) || (root->rchild->color == 0 && has_red_child(root->rchild))) {
        if (root->lchild->color == 0 && root->rchild->color == 0) {
            root->lchild->color = root->rchild->color = 1;
            root->color = 0;
            return root;
        }
        if (root->lchild->color == 0) {
            if (root->lchild->lchild->color != 0) {
                root->lchild = left_rotate(root->lchild);
            }
            root->lchild->color = root->color;
            root->color = 0;
            root = right_rotate(root);
        } else {
            if (root->rchild->rchild->color != 0) {
                root->rchild = right_rotate(root->rchild);
            }
            root->rchild->color = root->color;
            root->color = 0;
            root = left_rotate(root);
        }
    }
    return root;
}

Node *__insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) {
        root->lchild = __insert(root->lchild, key);
    } else {
        root->rchild = __insert(root->rchild, key);
    }
    root = insert_maintain(root);
    update_height(root);
    return root;
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = 1;
    return root;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != 2 && root->rchild->color != 2) return root;
    if (!has_red_child(root)) {
        if (root->lchild->color == 2) {
            if (!has_red_child(root->rchild)) {
                root->color += 1;
                root->lchild->color -= 1;
                root->rchild->color -= 1;
            } else {
                root->lchild->color = 1;
                if (root->rchild->rchild->color != 0) {
                    root->rchild->lchild->color = root->rchild->color;
                    root->rchild = 0;
                    root->rchild = right_rotate(root->rchild);
                }
                root->rchild->color = root->color;
                root = left_rotate(root);
                root->rchild->color = root->lchild->color = 1;
            }
        } else if (root->rchild->color == 2) {
            if (!has_red_child(root->lchild)) {
                root->color += 1;
                root->lchild->color -= 1;
                root->rchild->color -= 1;
            } else {
                root->rchild->color = 1;
                if (root->lchild->lchild->color != 0) {
                    root->lchild->rchild->color = root->lchild->color;
                    root->lchild = 0;
                    root->lchild = left_rotate(root->lchild);
                }
                root->lchild->color = root->color;
                root = right_rotate(root);
                root->rchild->color = root->lchild->color = 1;
            }
        }
    } else {
        if (root->lchild->color == 0) {
            root->lchild->color = root->color;
            root->color = 0;
            root = right_rotate(root);
            root->rchild = erase_maintain(root->rchild);
        } else {
            root->rchild->color = root->color;
            root->color = 0;
            root = left_rotate(root);
            root->lchild = erase_maintain(root->lchild);
        }
    }
    return root;
}

Node *precessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *__erase(Node *root, int key) {
    if (root == NIL) return NIL;
    if (root->key < key) {
        root->rchild = __erase(root->rchild, key);
    } else if (root->key > key) {
        root->lchild = __erase(root->lchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = (root->lchild == NIL ? root->rchild : root->lchild);
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            Node *temp = precessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    root = erase_maintain(root);
    update_height(root);
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


void my_print(int flag, int bit, int dis, int x, int y, Node *root) {
    MOVETO(y, x);
    if (root->color == 1) {
        printf("%d\n", root->key);
    } else {
        printf(RED_HL("%-*d\n"), bit / 2, root->key);
    }
    if (flag == 1) {
        for (int i = 1; i <= dis; i++) {
            MOVETO(y - i, x + i * 2 - 1);
            printf("/\n");
        }
    } else if (flag == 2) {
        for (int i = 1; i <= dis; i++) {
            MOVETO(y - i, x - i * 2 + 1);
            printf("\\\n");
        }
    }
    return ;
}

void my_output(int flag, int bit, int dis, int x, int y, Node *root) {
    if (root == NIL) return ;
    my_print(flag, bit, dis, x, y, root);
    my_output(1, bit, dis / 2, x - dis - bit, y + dis / 2 + 1, root->lchild);
    my_output(2, bit, dis / 2, x + dis + bit, y + dis / 2 + 1, root->rchild);
    return ;
}

int getMaxwidth(Node *root) {
    if (root == NIL) return 0;
    while (root->rchild != NIL) root = root->rchild;
    int maxvalue = root->key;
    int bit = 0;
    while (maxvalue) {
        bit++;
        maxvalue /= 10;
    }
    return bit;
}

int main() {
    struct winsize size;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
    // printf("%d\n",size.ws_col);
    // printf("%d\n",size.ws_row);
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op)
        {
        case 1:
            root = insert(root, val);
            break;
        case 2:
            root = erase(root, val);
            break;
        default:
            break;
        }
        CLEAR();
        int bit = getMaxwidth(root);
        my_output(0, bit, pow(2, root->h - 1), size.ws_col / 2, 1, root);
    }
    return 0;
}

