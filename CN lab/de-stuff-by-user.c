#include <stdio.h>

#define MAX_CAPACITY 5

void deStuff(int container[], int *size) {
    if (*size > 0) {
        int item = container[*size - 1];
        (*size)--;
        printf("Item %d de-stuffed from the container.\n", item);
    } else {
        printf("Container is empty! Nothing to de-stuff.\n");
    }
}

int main() {
    int container[MAX_CAPACITY];
    int size = 0;
    int item, choice;

    printf("Enter items to stuff into the container (max %d items):\n", MAX_CAPACITY);
    
    for (int i = 0; i < MAX_CAPACITY; i++) {
        printf("Enter item %d: ", i + 1);
        scanf("%d", &item);
        container[size] = item;
        size++;
    }

    do {
        printf("Do you want to de-stuff an item? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
        if (choice == 1) {
            deStuff(container, &size);
        }
    } while (choice == 1 && size > 0);

    return 0;
}
