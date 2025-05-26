#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bitStuff() {
  printf("\n===Bit stuffing===\n");

  char data[100];
  char stuffed[200];
  char flag[] = "01111110";

  printf("Enter the input binary seqence\n");
  scanf("%s", data);

  printf("You have entered the seqrnce %s\n",data);
  printf("the flag pattern is %s\n", flag);

  int i = 0, j = 0, count = 0;

  strcpy(stuffed, flag);
  j = strlen(flag);

  while (i < strlen(data)) {
    stuffed[j++] = data[i];

    if (data[i] == '1') {
      count++;
    } else {
      count = 0;
    }

    if (count == 5) {
      stuffed[j++] = '0';
      count = 0;
      printf("A zero was stuffed to the sequence\n");
    }
    i++;
  }
  
  strcat(stuffed + j, flag);
  stuffed[j + strlen(flag)] = '\0';

  printf("The final sequence is %s\n", stuffed);
}

void bitUnstuff() {
  char data[100];
  char stuffed[200];
  char flag[] = "01111110";

  printf("Enter the input binary seqence after bit stuffing\n");
  scanf("%s", stuffed);

  printf("You have entered the sequence %s\n", stuffed);
  printf("the flag pattern is %s\n", flag);

  int i = 0, j = 0, count = 0;

  i = strlen(flag);
  while (i < strlen(stuffed) - strlen(flag)) {
    data[j++] = stuffed[i];
    if (stuffed[i] == '1') {
      count++;
    } else {
      count = 0;
    }

    if (count == 5 && stuffed[i + 1] == '0') {
      i++;
      count == 0;
      printf("A zero was removed from the sequence\n");
    }
    i++;
  }
  data[j] = '\0';
  printf("The final sequence is %s\n", data);
}

int main()
{
  bitStuff();
  bitUnstuff();
  return EXIT_SUCCESS;
}
