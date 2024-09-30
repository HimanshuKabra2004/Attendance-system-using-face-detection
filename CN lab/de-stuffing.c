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
    int container[MAX_CAPACITY] = {10, 20, 30, 40, 50};
    int size = 5;

    deStuff(container, &size);
    deStuff(container, &size);
    deStuff(container, &size);

    return 0;
}
