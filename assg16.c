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

int main() {
    struct Node hashTable[SIZE];
    int choice, key, value;

    // Initialize hash table
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].key = 0;
        hashTable[i].value = 0;
    }

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                insert(hashTable, key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                value = search(hashTable, key);
                if (value == -1) {
                    printf("Key not found\n");
                } else {
                    printf("Value: %d\n", value);
                }
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(hashTable, key);
                break;
            case 4:
                display(hashTable);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
