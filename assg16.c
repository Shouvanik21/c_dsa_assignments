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
