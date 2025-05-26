#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void byteStuff() {
  printf("===This Program Stuffs Byte===\n");

  unsigned char data[100];
  unsigned char stuffed[200];
  unsigned char flag = 0x7E;
  unsigned char esc = 0x7D;

  int dataLen;
  printf("Enter the data length of the sequence\n");
  scanf("%d",&dataLen);

  printf("Enter the data seqnence\n");
  for (int i = 0;  i < dataLen; i++) {
    unsigned int temp;
    scanf("%X", &temp);
    data[i] = (unsigned char)temp;
  }

  printf("Original data \n");
  for (int i = 0;  i < dataLen; i++) {
    printf("%02x ", data[i]);
  }
  printf("\n");

  int j = 0;
  stuffed[j++] = flag;

  for (int i = 0; i< dataLen;i++) {
    if (data[i] == flag || data[i] == esc) {
      stuffed[j++] = esc;
      stuffed[j++] = data[i] ^ 0x20;
      printf("Stuffed byte %02X as ESC %02X\n", data[i], data[i] ^ 0x20);
    } else {
      stuffed[j++] = data[i];
    }
  }

  stuffed[j++] = flag;
  printf("Stuffed data \n");
  for (int i = 0;  i < j; i++) {
    printf("%02x ", stuffed[i]);
  }
  printf("\n");
  printf("\nFrame length: %d bytes\n", j);
}

void byteUnstuff() {
  printf("===This Program UnStuffs Byte===\n");

  unsigned char data[100];
  unsigned char stuffed[200];
  unsigned char flag = 0x7E;
  unsigned char esc = 0x7D;

  int dataLen;
  printf("Enter the stuffed data length of the sequence\n");
  scanf("%d",&dataLen);

  printf("Enter the stuffed seqnence\n");
  for (int i = 0;  i < dataLen; i++) {
    unsigned int temp;
    scanf("%X", &temp);
    stuffed[i] = (unsigned char)temp;
  }

  printf("Original data \n");
  for (int i = 0;  i < dataLen; i++) {
    printf("%02x ", stuffed[i]);
  }
  printf("\n");

  int j = 0;
  
  for (int i = 1; i< dataLen - 1;i++) {
    if (stuffed[i] == esc) {
      data[j++] = stuffed[i + 1] ^ 0x20;
      printf("UnStuffed byte %02X as ESC %02X\n", stuffed[i+1], stuffed[i+1] ^ 0x20);
      i++;
    } else {
      data[j++] = stuffed[i];
    }
  }

  printf("UnStuffed data \n");
  for (int i = 0;  i < j; i++) {
    printf("%02x ", data[i]);
  }
  printf("\n");
  printf("\nFrame length: %d bytes\n", j);

}

int main()
{
  byteStuff();
  byteUnstuff();
  return EXIT_SUCCESS;
}
