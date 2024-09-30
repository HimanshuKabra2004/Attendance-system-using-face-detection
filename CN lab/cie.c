#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct frame {
    int fslno;
    char finfo[20];
};

struct frame *arr;
int n;

void sort() {
    int i, j;
    struct frame temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].fslno > arr[j + 1].fslno) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i;
    printf("\nEnter the number of frames: ");
    scanf("%d", &n);

    // Allocate memory for the array of frames
    arr = (struct frame*)malloc(n * sizeof(struct frame));
    if (arr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (i = 0; i < n; i++) {
        arr[i].fslno = rand() % 50;
        printf("\nEnter the frame contents for sequence number %d: ", arr[i].fslno);
        scanf("%s", arr[i].finfo);
    }

    sort();

    printf("\nThe frames in sequence:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\n", arr[i].fslno, arr[i].finfo);
    }

    // Free the allocated memory
    free(arr);

    return 0;
}