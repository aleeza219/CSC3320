#include <stdio.h>
#include <string.h>
/***
Author: Aleeza Iftikhar
***/
int main(void) {
  char word[20];
  char smallest_word[20];
  char largest_word[20];
  printf("Enter word: ");
  gets(word);
  strcpy(smallest_word, word);
  strcpy(largest_word, word);

  while (strlen(word) != 4){
    if(strcmp(word, smallest_word)<0){
      strcpy(smallest_word, word);
    }else if(strcmp(word, largest_word)>0){
      strcpy(largest_word, word);
    }
    printf("Enter word: ");
    gets(word);
  }

  printf("\nSmallest word: %s", smallest_word);
  printf("\nLargest word: %s", largest_word);
  return 0;
}
