#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *root = NULL;

// insert
void insert(int value) {
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = value;
        root->left = root->right = NULL;
        return;
    }

    struct Node *temp = root, *parent = NULL;

    while (temp != NULL) {
        parent = temp;
        if (value < temp->data)
            temp = temp->left;
        else if (value > temp->data)
            temp = temp->right;
        else
            return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;

    if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// find minimum (used for successor)
struct Node* findMin(struct Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// 🔥 delete function
struct Node* deleteNode(struct Node* node, int key) {
    if (node == NULL) return NULL;

    if (key < node->data) {
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->data) {
        node->right = deleteNode(node->right, key);
    }
    else {
        // CASE 1 & 2: one child or no child
        if (node->left == NULL) {
            struct Node* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            struct Node* temp = node->left;
            free(node);
            return temp;
        }

        // CASE 3: two children
        struct Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

// inorder traversal
void inorder(struct Node *node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

int main() {

    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    printf("Before Deletion: ");
    inorder(root);

    root = deleteNode(root, 50);

    printf("\nAfter Deletion: ");
    inorder(root);

    return 0;
}
