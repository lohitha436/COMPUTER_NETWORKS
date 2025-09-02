#include <stdio.h>
#include <string.h>

#define FLAG "01111110"

void bitStuffing(char *input, char *output) {
    int count = 0;
    int j = 0;
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        output[j++] = input[i];

        if (input[i] == '1') {
            count++;
            if (count == 5) {
                // Insert a '0' after five consecutive '1's
                output[j++] = '0';
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    output[j] = '\0';  // Null-terminate output string
}

int main() {
    char message[1000];
    char stuffed[2000];  // Output buffer, double size for safety
    char finalFrame[2050];
    
    printf("Enter binary message (only 0 and 1): ");
    scanf("%s", message);

    // Do bit stuffing
    bitStuffing(message, stuffed);

    // Add flag at start and end
    strcpy(finalFrame, FLAG);
    strcat(finalFrame, stuffed);
    strcat(finalFrame, FLAG);

    printf("Original message: %s\n", message);
    printf("After bit stuffing: %s\n", stuffed);
    printf("Final frame with flags: %s\n", finalFrame);

    return 0;
}
