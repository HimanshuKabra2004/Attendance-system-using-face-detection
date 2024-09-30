#include <stdio.h>
#include <string.h>

void character_count_framing(char *data[], int n) {
    for (int i = 0; i < n; i++) {
        int length = strlen(data[i]);
        printf("%d%s\n", length, data[i]);
    }
}

int main() {
    char *data[] = {"Hello", "World", "DataLink"};
    int n = sizeof(data) / sizeof(data[0]);
    character_count_framing(data, n);
    return 0;
}