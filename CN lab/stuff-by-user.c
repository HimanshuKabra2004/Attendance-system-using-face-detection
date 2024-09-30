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
    int item;

    printf("Enter items to stuff into the container (max %d items):\n", MAX_CAPACITY);
    
    for (int i = 0; i < MAX_CAPACITY; i++) {
        printf("Enter item %d: ", i + 1);
        scanf("%d", &item);
        stuff(container, &size, item);
    }

    return 0;
}
