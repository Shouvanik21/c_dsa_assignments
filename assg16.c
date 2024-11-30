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
