#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // for sleep()
#define BUCKET_SIZE 512
int bucket_level = 0; // Current bucket level
// Function to simulate the input to the leaky bucket
void bktInput(int a, int b) { // a = packet size, b = output rate
    // Check for overflow
    if (bucket_level + a > BUCKET_SIZE) {
        printf("\n\t\tBucket overflow! Packet dropped.\n");
        return;
    }
    bucket_level += a;
    printf("\n\t\tPacket accepted. Bucket level = %d bytes\n", bucket_level);
    // Leak data at steady rate
    while (bucket_level > 0) {
        int leaked = (bucket_level >= b) ? b : bucket_level;
        bucket_level -= leaked;
        printf("\t\t%d bytes outputted. Remaining in bucket = %d bytes\n", leaked, bucket_level);
        sleep(1); // simulate 1-second output interval
    }
    printf("\t\tBucket output successful.\n");
}

int main() {
    int op, pktSize;
    srand(time(0));
    printf("Enter output rate: ");
    scanf("%d", &op);
    for (int i = 1; i <= 5; i++) {
        sleep(rand() % 2); // Simulate random packet arrival
        pktSize = rand() % 1000; // Random packet size
        printf("\nPacket no %d\tPacket size = %d", i, pktSize);
        bktInput(pktSize, op);
    }
    printf("\nAll packets processed. Final bucket level = %d bytes\n", bucket_level);
    return 0;
}
