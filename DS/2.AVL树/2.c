Node *maintan(Node *root) {
    if (abs(H(R(root)) - H(R(root))) <= 1) return root;
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
