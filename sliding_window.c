#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 100

void slidingWindowProtocol() {
    int totalFrames, windowSize;
    int windowStart = 0;
    int frameStatus[MAX_FRAMES] = {0}; // 0: not sent, 1: sent, 2: acked

    printf("\n=== SLIDING WINDOW PROTOCOL SIMULATION ===\n");
    printf("Enter total number of frames (max %d): ", MAX_FRAMES);
    scanf("%d", &totalFrames);
    printf("Enter window size: ");
    scanf("%d", &windowSize);

    printf("\nSimulating...\n");

    while (windowStart < totalFrames) {
        int windowEnd = windowStart + windowSize;
        if (windowEnd > totalFrames) windowEnd = totalFrames;

        // Send all frames in window
        for (int i = windowStart; i < windowEnd; i++) {
            if (frameStatus[i] == 0) {
                printf("Sending Frame %d\n", i);
                frameStatus[i] = 1;
            }
        }

        // Receive ACKs (simulate with 75% success rate)
        for (int i = windowStart; i < windowEnd; i++) {
            if (frameStatus[i] == 1) {
                int ackLost = rand() % 4; // 25% chance of ACK loss
                if (ackLost != 0) {
                    printf("ACK %d received\n", i);
                    frameStatus[i] = 2;
                } else {
                    printf("ACK %d lost. Will retransmit Frame %d\n", i, i);
                    frameStatus[i] = 0;
                }
            }
        }

        // Slide window
        while (windowStart < totalFrames && frameStatus[windowStart] == 2) {
            windowStart++;
        }

        printf("Window now at: [%d - %d]\n\n", windowStart,
               (windowStart + windowSize - 1 < totalFrames ? windowStart + windowSize - 1 : totalFrames - 1));
    }

    printf("All frames transmitted and acknowledged successfully!\n");
}

int main() {
    slidingWindowProtocol();
    return 0;
}

