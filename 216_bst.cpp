int minValue(struct Node *root) {
    if (root == NULL) {
        return -1;
    }

    int ans = root->data;

    while (root != NULL) {
        ans = root->data;
        root = root->left;
    }

    return ans;
}
