#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ---------- HUFFMAN PART (SIMPLIFIED) ----------

// Structure for Huffman node
struct HuffNode {
    char ch;
    int freq;
    struct HuffNode *left, *right;
};

// Create node
struct HuffNode* newNode(char ch, int freq) {
    struct HuffNode* node = (struct HuffNode*)malloc(sizeof(struct HuffNode));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Print simple binary codes (demo purpose)
void generateCodes(char str[]) {
    printf("\nHuffman Encoding (Simple):\n");
    for(int i = 0; str[i]; i++) {
        printf("%c -> %d\n", str[i], str[i] % 2); // dummy encoding
    }
}

// Encode string (simple binary form)
void encode(char str[], char encoded[]) {
    int k = 0;
    for(int i = 0; str[i]; i++) {
        encoded[k++] = (str[i] % 2) + '0';
    }
    encoded[k] = '\0';
}

// Decode string
void decode(char encoded[], char original[]) {
    int k = 0;
    for(int i = 0; encoded[i]; i++) {
        if(encoded[i] == '0')
            original[k++] = 'a'; // demo
        else
            original[k++] = 'b';
    }
    original[k] = '\0';
}


// ---------- B-TREE PART (BASIC) ----------

struct BTreeNode {
    int keys[10];
    int n;
};

// Insert into B-Tree (simple array)
void insertBTree(struct BTreeNode* node, int key) {
    node->keys[node->n++] = key;
}

// Display B-Tree
void displayBTree(struct BTreeNode* node) {
    printf("\nB-Tree contents:\n");
    for(int i = 0; i < node->n; i++)
        printf("%d ", node->keys[i]);
}

// Search
int searchBTree(struct BTreeNode* node, int key) {
    for(int i = 0; i < node->n; i++) {
        if(node->keys[i] == key)
            return 1;
    }
    return 0;
}


// ---------- MAIN COMBINED SYSTEM ----------

int main() {
    char input[50], encoded[100], decoded[50];
    struct BTreeNode tree;
    tree.n = 0;

    printf("Enter string: ");
    scanf("%s", input);

    // Step 1: Huffman Encoding
    generateCodes(input);
    encode(input, encoded);

    printf("\nEncoded String: %s\n", encoded);

    // Step 2: Store in B-Tree (convert to number)
    int key = atoi(encoded); // convert binary string to integer
    insertBTree(&tree, key);

    displayBTree(&tree);

    // Step 3: Search
    printf("\nSearching key %d...\n", key);
    if(searchBTree(&tree, key))
        printf("Found in B-Tree!\n");
    else
        printf("Not Found!\n");

    // Step 4: Decode
    decode(encoded, decoded);
    printf("\nDecoded String: %s\n", decoded);

    return 0;
}