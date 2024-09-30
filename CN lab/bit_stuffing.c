#include <stdio.h>
#include <string.h>

void bit_stuffing(char *data[], int n) {
    for (int i = 0; i < n; i++) {
        char stuffed_frame[256] = "";
        int count = 0;
        int len = strlen(data[i]);
        
        for (int j = 0; j < len; j++) {
            if (data[i][j] == '1') {
                count++;
            } else {
                count = 0;
            }
            strncat(stuffed_frame, &data[i][j], 1);
            if (count == 5) {
                strcat(stuffed_frame, "0");
                count = 0;
            }
        }
        printf("%s\n", stuffed_frame);
    }
}

int main() {
    char *data[] = {"01111110", "111110101111", "0111101111111"};
    int n = sizeof(data) / sizeof(data[0]);
    bit_stuffing(data, n);
    return 0;
}