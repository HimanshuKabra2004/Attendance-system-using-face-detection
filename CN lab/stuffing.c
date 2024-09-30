#include <stdio.h>

#define MAX_CAPACITY 5

void stuff(int container[], int *size, int item) {
    if (*size < MAX_CAPACITY) {
        container[*size] = item;
        (*size)++;
        printf("Item %d stuffed into the container.\n", item);
    } else {
        printf("Container is full! Cannot stuff item %d.\n", item);
    }
}

int main() {
    int container[MAX_CAPACITY];
    int size = 0;

    stuff(container, &size, 10);
    stuff(container, &size, 20);
    stuff(container, &size, 30);
    stuff(container, &size, 40);
    stuff(container, &size, 50);

    return 0;
}
