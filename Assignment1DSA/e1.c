#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char data, int freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Simple function to print codes
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Build simple Huffman Tree (without heap for simplicity)
struct Node* buildTree(char data[], int freq[], int n) {
    struct Node *left, *right, *top;

    struct Node* nodes[MAX];
    for (int i = 0; i < n; i++)
        nodes[i] = createNode(data[i], freq[i]);

    while (n > 1) {
        int min1 = 0, min2 = 1;

        if (nodes[min1]->freq > nodes[min2]->freq) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }

        for (int i = 2; i < n; i++) {
            if (nodes[i]->freq < nodes[min1]->freq) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->freq < nodes[min2]->freq) {
                min2 = i;
            }
        }

        left = nodes[min1];
        right = nodes[min2];

        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        nodes[min1] = top;
        nodes[min2] = nodes[n - 1];
        n--;
    }

    return nodes[0];
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = 6;

    struct Node* root = buildTree(arr, freq, n);

    int codes[MAX];
    printCodes(root, codes, 0);

    return 0;
}