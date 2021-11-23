#include <stdio.h>
/******
Author: Aleeza Iftikhar
******/
//strcpy function:
char* strcpy (char* strDest, const char* strSrc){
  char *temp = strDest;
  int i = 0;
  while (strSrc[i] != '\0' && strDest != strSrc){
    strDest[i] = strSrc[i];//copy characters of source in destination string
    i++;
  }
  return temp;
}
//main class for testing:
int main(void) {
  char destination[1001];
  char source[1000];
  printf("Enter a string: ");
  gets(source);
  // printf("source: %s\n", source);

  printf("After calling strcpy: %s\n", strcpy(destination, source));
  
  printf("Verifiying desination is: %s\n", destination);
  return 0;
}
