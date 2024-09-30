#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + key - 'A') % 26 + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = (ch + key - 'a') % 26 + 'a';
        }
        message[i] = ch;
    }
}

void decrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - key - 'A' + 26) % 26 + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - key - 'a' + 26) % 26 + 'a';
        }
        message[i] = ch;
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter key (number of positions to shift): ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}
