#include <stdio.h>
#include <string.h>

int main() {
    int n, i;
    char frames[10][50];
    
    printf("Enter number of frames: ");
    scanf("%d", &n);
    
    // Read each frame
    for(i = 0; i < n; i++) {
        printf("Enter frame %d: ", i + 1);
        scanf("%s", frames[i]);
    }
    
    printf("\n--- Character Count Framing ---\n");
    printf("Transmitted Frames:\n");

    // Encode frames using Character Count Method
    for(i = 0; i < n; i++) {
        int length = strlen(frames[i]) + 1;  // +1 to include count byte
        printf("%d%s ", length, frames[i]);
    }

    printf("\n\n--- Receiver Side Frame Extraction ---\n");

    for(i = 0; i < n; i++) {
        int length = strlen(frames[i]) + 1;
        printf("Received Frame %d: %s (Length=%d)\n", i + 1, frames[i], length);
    }

    return 0;
}
