#include <stdio.h>
#include <stdlib.h>

#define T 3   // Minimum degree (order)

// B-Tree Node
struct BTreeNode {
    int keys[2*T-1];
    struct BTreeNode *C[2*T];
    int n;      // number of keys
    int leaf;   // is leaf or not
};

// Create Node
struct BTreeNode* createNode(int leaf) {
    struct BTreeNode* node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    return node;
}

// Traverse (Display)
void traverse(struct BTreeNode* root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->n; i++) {
            if (!root->leaf)
                traverse(root->C[i]);
            printf("%d ", root->keys[i]);
        }
        if (!root->leaf)
            traverse(root->C[i]);
    }
}

// Search
struct BTreeNode* search(struct BTreeNode* root, int k) {
    int i = 0;
    while (i < root->n && k > root->keys[i])
        i++;

    if (i < root->n && root->keys[i] == k)
        return root;

    if (root->leaf)
        return NULL;

    return search(root->C[i], k);
}

// Split Child
void splitChild(struct BTreeNode* x, int i, struct BTreeNode* y) {
    struct BTreeNode* z = createNode(y->leaf);
    z->n = T - 1;

    for (int j = 0; j < T-1; j++)
        z->keys[j] = y->keys[j+T];

    if (!y->leaf) {
        for (int j = 0; j < T; j++)
            z->C[j] = y->C[j+T];
    }

    y->n = T - 1;

    for (int j = x->n; j >= i+1; j--)
        x->C[j+1] = x->C[j];

    x->C[i+1] = z;

    for (int j = x->n-1; j >= i; j--)
        x->keys[j+1] = x->keys[j];

    x->keys[i] = y->keys[T-1];
    x->n++;
}

// Insert Non-Full
void insertNonFull(struct BTreeNode* x, int k) {
    int i = x->n - 1;

    if (x->leaf) {
        while (i >= 0 && k < x->keys[i]) {
            x->keys[i+1] = x->keys[i];
            i--;
        }
        x->keys[i+1] = k;
        x->n++;
    } else {
        while (i >= 0 && k < x->keys[i])
            i--;

        i++;
        if (x->C[i]->n == 2*T-1) {
            splitChild(x, i, x->C[i]);

            if (k > x->keys[i])
                i++;
        }
        insertNonFull(x->C[i], k);
    }
}

// Insert
struct BTreeNode* insert(struct BTreeNode* root, int k) {
    if (root == NULL) {
        root = createNode(1);
        root->keys[0] = k;
        root->n = 1;
        return root;
    }

    if (root->n == 2*T-1) {
        struct BTreeNode* s = createNode(0);
        s->C[0] = root;

        splitChild(s, 0, root);

        int i = 0;
        if (k > s->keys[0])
            i++;
        insertNonFull(s->C[i], k);

        return s;
    } else {
        insertNonFull(root, k);
        return root;
    }
}

// MAIN
int main() {
    struct BTreeNode* root = NULL;

    int arr[] = {10, 20, 5, 6, 12, 30, 7, 17};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++)
        root = insert(root, arr[i]);

    printf("Traversal of B-Tree:\n");
    traverse(root);

    int key = 6;
    if (search(root, key))
        printf("\nKey %d found\n", key);
    else
        printf("\nKey %d not found\n", key);

    return 0;
} 