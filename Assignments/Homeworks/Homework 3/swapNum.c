#include <stdio.h>
#include <string.h> //to find string length
/***
Author: Aleeza Iftikhar
Howmework 4: Part 2 - Question 4
Program: Read 2 sentences, and swap their numeric characters without use of third variable (note: keep lengths of sentences identical)
***/

//Function to swap numbers without use of third variable
void swap(char *a, char *b){
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

int main(void) {

  char sentence1[] = "She may have 23 dollars, CSC 3320 is my subject.";
  char sentence2[] = "Ok, I may be 10 yrs old, my ID couldn't be 1234.";

  printf("Before swapping numeric charcters: \n");
  printf("Sentence1: %s\nSentence2: %s\n\n",sentence1, sentence2);
  
  if(strlen(sentence1)==strlen(sentence2)){
  int length = strlen(sentence1);
  int i=0,j=0;
  //reading sentences:
  while(i<length){
    //finding num in sentence 1
    if(sentence1[i]>=48 && sentence1[i]<=57){
      while(j<length){
        //finding num in sentence 2
        if(sentence2[j]>=48 && sentence2[j]<=57){
        //swapping numeric charcters only
        swap(&sentence1[i], &sentence2[j]);
        j++;
        break;
        }
      j++;
      }
    }
    i++;
  }
    //lengths of sentences will remain identical after swapping
  printf("After swapping numeric charcters: \n");
  printf("Sentence1: %s\nSentence2: %s\n\n",sentence1, sentence2);
  }else{
    printf("Error: Lengths of sentences are not identical.\n");
  }

  return 0;
}
