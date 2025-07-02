#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
// Function to encrypt the string
void encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; ++i) {
        text[i] = text[i] + key;
    }
}
// Function to decrypt the string
void decrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; ++i) {
        text[i] = text[i] - key;
    }
}
int main() {
    char message[MAX_LEN];
    int key;
    printf("Enter a message: ");
    fgets(message, MAX_LEN, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character

    printf("Enter a key (number): ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}
