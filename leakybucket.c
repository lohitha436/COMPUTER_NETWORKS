#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // <-- Added for sleep()

#define BUCKET_SIZE 512

// Function to simulate the input to the leaky bucket
void bktInput(int a, int b) {
    // Check if the packet size exceeds the bucket size
    if (a > BUCKET_SIZE) {
        printf("\n\t\tBucket overflow");
    } else {
        sleep(1); // Simulate processing delay

        // Process the packet
        while (a > b) {
            printf("\n\t\t%d bytes outputted.", b);
            a -= b;
            sleep(1); // Simulate output delay
        }

        if (a > 0) {
            printf("\n\t\tLast %d bytes sent", a);
        }

        printf("\n\t\tBucket output successful");
    }
}

int main() {
    int op, pktSize;
    srand(time(0));  // Seed random number generator

    printf("Enter output rate: ");
    scanf("%d", &op);

    for (int i = 1; i <= 5; i++) {
        sleep(rand() % 2);  // Simulate random arrival

        pktSize = rand() % 1000;  // Random packet size

        printf("\nPacket no %d", i);
        printf("\tPacket size = %d", pktSize);

        bktInput(pktSize, op);
    }

    return 0;
}
