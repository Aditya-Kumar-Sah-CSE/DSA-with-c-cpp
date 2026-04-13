#include <stdio.h>
#include <string.h>

// Simple encode (dummy Huffman for demo)
void encode(char *str) {
    for (int i = 0; str[i]; i++) {
        printf("%d ", str[i]);  // ASCII as encoded form
    }
    printf("\n");
}

int main() {
    char word[50];

    printf("Enter word: ");
    scanf("%s", word);

    printf("Encoded: ");
    encode(word);

    printf("Stored in B-Tree (conceptual)\n");

    printf("Decoded: %s\n", word);

    return 0;
}