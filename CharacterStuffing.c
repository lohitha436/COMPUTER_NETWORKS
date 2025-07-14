#include <stdio.h>
#include <string.h>

#define FLAG "FLAG"
#define ESC "ESC"

void character_stuffing(char *input, char *output) {
    int i = 0, j = 0;
    int len = strlen(input);

    for (i = 0; i < len; i++) {
        if (strncmp(&input[i], FLAG, strlen(FLAG)) == 0) {
            strcpy(&output[j], ESC);
            j += strlen(ESC);
            strcpy(&output[j], FLAG);
            j += strlen(FLAG);
            i += strlen(FLAG) - 1;
        } else if (strncmp(&input[i], ESC, strlen(ESC)) == 0) {
            strcpy(&output[j], ESC);
            j += strlen(ESC);
            strcpy(&output[j], ESC);
            j += strlen(ESC);
            i += strlen(ESC) - 1;
        } else {
            output[j++] = input[i];
        }
    }

    output[j] = '\0';
}

int main() {
    char message[1000], stuffed[2000], final[2100];

    printf("Enter message: ");
    scanf("%s", message);

    character_stuffing(message, stuffed);

    strcpy(final, FLAG);
    strcat(final, stuffed);
    strcat(final, FLAG);

    printf("Stuffed message: %s\n", final);

    return 0;
}
