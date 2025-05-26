#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void crc(char dividend[], char generator[], char *remainder) {
  int dataLen = strlen(dividend);
  int genLen = strlen(generator);

  for (int i = 0; i < dataLen - genLen + 1; i++) {
    if (dividend[i] == '1') {
      for (int j = 0;j < genLen; j++) {
        dividend[i+j] = ((dividend[i+j] - '0') ^ (generator[j] - '0')) + '0';
        // printf("The dividend is %s\n", dividend);
      }
    }
  }
  
  strncpy(remainder, dividend + dataLen - genLen + 1, genLen - 1);
  remainder[genLen] = '\0';
  // printf("The remainder is = %s\n", remainder);
}

int crcCheck(char dividend[], char generator[]) {
  int dataLen = strlen(dividend);
  int genLen = strlen(generator);

  for (int i = 0; i < dataLen - genLen + 1; i++) {
    if (dividend[i] == '1') {
      for (int j = 0;j < genLen; j++) {
        dividend[i+j] = ((dividend[i+j] - '0') ^ (generator[j] - '0')) + '0';
        // printf("The dividend is %s\n", dividend);
      }
    }
  }

  if (strchr(dividend,'1')) {
    return 0;
  }
  else {
    return 1;
  }
}

int main()
{
  char rem[20];
  char data[100];
  char generator[20];
  char dividend[120];
  char input[100];

  printf("Enter the the input sequence\n");
  scanf("%s",data);

  printf("Enter the the generator sequence\n");
  scanf("%s",generator);

  int genLen = strlen(generator);

  printf("You have entered the following sequence\nData: %s\nGenerator: %s\n",data,generator);

  strcpy(dividend,data);
  for (int i =0;i < genLen-1; i++) {
    strcat(dividend,"0");
  }
  crc(dividend,generator,rem);
  printf("The remainder is = %s\n", rem);

  printf("The final sequence is %s%s\n",data,rem);

  printf("Check the data for CRC \n");
  printf("Enter the the input sequence\n");
  scanf("%s",input);

  printf("You have entered the following sequence\nData: %s\nGenerator: %s\n",input,generator);
  
  if (crcCheck(input,generator)) {
    printf("The sequence is correct\n");
  } else {
    printf("The sequence has error\n");
  }
  return EXIT_SUCCESS;
}
