#include <stdio.h>
#include <string.h>

#define MAX 100

// ---------- HUFFMAN (SIMPLIFIED STATIC CODES) ----------
char ch[] = {'a','b','c','d'};
char codes[][10] = {"0","10","110","111"};
int n = 4;

// Encode function
void encode(char word[], char encoded[]) {
    encoded[0] = '\0';
    for(int i=0; word[i]; i++) {
        for(int j=0; j<n; j++) {
            if(word[i] == ch[j]) {
                strcat(encoded, codes[j]);
            }
        }
    }
}

// Decode function
void decode(char encoded[], char decoded[]) {
    int i=0, k=0;

    while(encoded[i]) {
        if(encoded[i]=='0') {
            decoded[k++]='a';
            i++;
        }
        else if(encoded[i]=='1' && encoded[i+1]=='0') {
            decoded[k++]='b';
            i+=2;
        }
        else if(encoded[i]=='1' && encoded[i+1]=='1' && encoded[i+2]=='0') {
            decoded[k++]='c';
            i+=3;
        }
        else {
            decoded[k++]='d';
            i+=3;
        }
    }
    decoded[k]='\0';
}

// ---------- B-TREE (SIMPLIFIED USING ARRAY) ----------
char btree[MAX][MAX];
int size = 0;

// Insert into "B-Tree"
void insert(char str[]) {
    strcpy(btree[size++], str);
}

// Search
int search(char key[]) {
    for(int i=0;i<size;i++) {
        if(strcmp(btree[i], key)==0)
            return i;
    }
    return -1;
}

// ---------- MAIN ----------
int main() {
    char words[3][MAX] = {"ab", "ac", "bd"};
    char encoded[MAX], decoded[MAX];

    // Step 1 + 2: Encode and Store
    for(int i=0;i<3;i++) {
        encode(words[i], encoded);
        insert(encoded);
        printf("Word: %s -> Encoded: %s\n", words[i], encoded);
    }

    // Step 3: Search
    char query[MAX];
    printf("\nEnter word to search: ");
    scanf("%s", query);

    encode(query, encoded);
    int pos = search(encoded);

    // Step 4: Decode
    if(pos != -1) {
        decode(encoded, decoded);
        printf("Found! Decoded word: %s\n", decoded);
    } else {
        printf("Word not found\n");
    }

    return 0;
}