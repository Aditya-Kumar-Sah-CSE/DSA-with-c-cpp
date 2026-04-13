#include <stdio.h>
#include <stdlib.h>

#define T 2

struct BTreeNode {
    int keys[2*T-1];
    struct BTreeNode* children[2*T];
    int n;
    int leaf;
};

struct BTreeNode* createNode(int leaf) {
    struct BTreeNode* node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    return node;
}

void traverse(struct BTreeNode* root) {
    int i;
    for (i = 0; i < root->n; i++) {
        if (!root->leaf)
            traverse(root->children[i]);
        printf("%d ", root->keys[i]);
    }
    if (!root->leaf)
        traverse(root->children[i]);
}

void insert(struct BTreeNode* root, int k) {
    int i = root->n - 1;

    if (root->leaf) {
        while (i >= 0 && root->keys[i] > k) {
            root->keys[i + 1] = root->keys[i];
            i--;
        }
        root->keys[i + 1] = k;
        root->n++;
    }
}

int main() {
    struct BTreeNode* root = createNode(1);

    insert(root, 10);
    insert(root, 20);
    insert(root, 5);

    printf("Traversal: ");
    traverse(root);

    return 0;
}