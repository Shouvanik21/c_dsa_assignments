#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10 

struct Node {
    int key;
    int value;
};

int hash(int key) {
    return key % SIZE;
}

void insert(struct Node *hashTable, int key, int value) {
    int index = hash(key);
    int i = 0;

    while (hashTable[index].key != 0 && hashTable[index].key != key) {
        index = (index + i) % SIZE;
        i++;
    }

    hashTable[index].key = key;
    hashTable[index].value = value;
}

int search(struct Node *hashTable, int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[index].key != 0) {
        if (hashTable[index].key == key) {
            return hashTable[index].value;
        }
        index = (index + i) % SIZE;
        i++;
    }

    return -1; // Key not found
}

void delete(struct Node *hashTable, int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[index].key != 0) {
        if (hashTable[index].key == key) {
            hashTable[index].key = 0;
            hashTable[index].value = 0;
            return;
        }
        index = (index + i) % SIZE;
        i++;
    }
}

void display(struct Node *hashTable) {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        if (hashTable[i].key == 0) {
            printf("Empty\n");
        } else {
            printf("Key: %d, Value: %d\n", hashTable[i].key, hashTable[i].value);
        }
    }
}
