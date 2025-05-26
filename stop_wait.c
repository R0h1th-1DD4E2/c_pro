void stopAndWaitProtocol() {
    printf("\n=== STOP AND WAIT PROTOCOL SIMULATION ===\n");
    
    int totalFrames, windowSize = 1;
    int ackReceived = 0, currentFrame = 0;
    int timeout = 3; // seconds
    
    printf("Enter total number of frames to send: ");
    scanf("%d", &totalFrames);
    
    printf("\nSimulating Stop and Wait Protocol:\n");
    printf("Window Size: %d\n", windowSize);
    printf("Timeout: %d seconds\n\n", timeout);
    
    while (currentFrame < totalFrames) {
        printf("Sender: Sending Frame %d\n", currentFrame);
        
        // Simulate transmission delay
        printf("Frame %d transmitted...\n", currentFrame);
        
        // Simulate ACK reception (random for demo)
        int ackLost = rand() % 5; // 20% chance of ACK loss
        
        if (ackLost == 0) {
            printf("ACK for Frame %d LOST!\n", currentFrame);
            printf("Timeout occurred! Retransmitting Frame %d\n\n", currentFrame);
        } else {
            printf("Receiver: Frame %d received successfully\n", currentFrame);
            printf("Receiver: Sending ACK %d\n", currentFrame);
            printf("Sender: ACK %d received\n\n", currentFrame);
            currentFrame++;
        }
        
        // Simulate delay
        for (int i = 0; i < 100000000; i++); // Simple delay
    }
    
    printf("All frames transmitted successfully!\n");
    printf("Total frames sent: %d\n", totalFrames);
    printf("Protocol efficiency: Low (due to waiting for each ACK)\n");
}
