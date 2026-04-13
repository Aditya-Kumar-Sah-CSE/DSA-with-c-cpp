#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Node
struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

// Min Heap
struct MinHeap {
    int size;
    struct Node* arr[MAX];
};

// Create node
struct Node* createNode(char ch, int freq) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->ch = ch;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Swap
void swap(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

// Heapify
void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < heap->size && heap->arr[l]->freq < heap->arr[smallest]->freq)
        smallest = l;

    if (r < heap->size && heap->arr[r]->freq < heap->arr[smallest]->freq)
        smallest = r;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

// Insert
void insert(struct MinHeap* heap, struct Node* node) {
    int i = heap->size++;
    heap->arr[i] = node;

    while (i && heap->arr[i]->freq < heap->arr[(i-1)/2]->freq) {
        swap(&heap->arr[i], &heap->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Extract Min
struct Node* extractMin(struct MinHeap* heap) {
    struct Node* temp = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapify(heap, 0);
    return temp;
}

// Frequency
void getFrequency(char str[], char ch[], int freq[], int *n) {
    int visited[256] = {0};
    *n = 0;

    for(int i=0; str[i]; i++) {
        if(!visited[str[i]]) {
            int count = 0;
            for(int j=0; str[j]; j++) {
                if(str[i] == str[j])
                    count++;
            }
            ch[*n] = str[i];
            freq[*n] = count;
            visited[str[i]] = 1;
            (*n)++;
        }
    }
}

// Build Tree
struct Node* buildTree(char ch[], int freq[], int n) {
    struct MinHeap heap;
    heap.size = 0;

    for(int i=0;i<n;i++)
        insert(&heap, createNode(ch[i], freq[i]));

    while(heap.size > 1) {
        struct Node* left = extractMin(&heap);
        struct Node* right = extractMin(&heap);

        struct Node* new = createNode('$', left->freq + right->freq);
        new->left = left;
        new->right = right;

        insert(&heap, new);
    }

    return extractMin(&heap);
}

// Store codes
void storeCodes(struct Node* root, char ch[], char codes[][MAX], int code[], int top) {
    if(root->left) {
        code[top]=0;
        storeCodes(root->left, ch, codes, code, top+1);
    }
    if(root->right) {
        code[top]=1;
        storeCodes(root->right, ch, codes, code, top+1);
    }

    if(!root->left && !root->right) {
        for(int i=0; ch[i]; i++) {
            if(ch[i] == root->ch) {
                for(int j=0;j<top;j++)
                    codes[i][j] = code[j] + '0';
                codes[i][top] = '\0';
            }
        }
    }
}

// Encode
void encode(char str[], char ch[], char codes[][MAX], int n, char encoded[]) {
    encoded[0] = '\0';

    for(int i=0; str[i]; i++) {
        for(int j=0; j<n; j++) {
            if(str[i] == ch[j]) {
                strcat(encoded, codes[j]);
            }
        }
    }
}

// Decode
void decode(struct Node* root, char encoded[], char decoded[]) {
    struct Node* curr = root;
    int k = 0;

    for(int i=0; encoded[i]; i++) {
        if(encoded[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;

        if(!curr->left && !curr->right) {
            decoded[k++] = curr->ch;
            curr = root;
        }
    }
    decoded[k] = '\0';
}
int verify(char original[], char decoded[]) {
    if(strcmp(original, decoded) == 0)
        return 1;
    else
        return 0;
}
// Main
int main() {
    char str[MAX];
    char ch[MAX];
    int freq[MAX], n;

    char codes[MAX][MAX];
    int code[MAX];
    char encoded[1000];

    printf("Enter string: ");
    scanf("%s", str);++
    // Frequency
    getFrequency(str, ch, freq, &n);

    printf("\nFrequencies:\n");
    for(int i=0;i<n;i++)
        printf("%c: %d\n", ch[i], freq[i]);

    // Build tree
    struct Node* root = buildTree(ch, freq, n);

    // Generate codes
    storeCodes(root, ch, codes, code, 0);

    printf("\nHuffman Codes:\n");
    for(int i=0;i<n;i++)
        printf("%c: %s\n", ch[i], codes[i]);

    // Encode
    encode(str, ch, codes, n, encoded);
    printf("\nEncoded string: %s\n", encoded);

  char decoded[MAX];

// Decode
decode(root, encoded, decoded);

printf("Decoded string: %s\n", decoded);

// Verification
if(verify(str, decoded))
    printf("Verification: SUCCESSFULL \n");
else
    printf("Verification: FAILED \n");

    return 0;
}