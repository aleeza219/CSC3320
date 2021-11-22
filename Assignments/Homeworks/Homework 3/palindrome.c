#include <stdio.h>//for printing
#include <stdbool.h>//for boolean data type
#include <string.h>//for string length
/*****
Author: Aleeza Iftikhar
Homework 4: Part 2 - Question 3
*****/

//isPalindrome function returns true or false, depending on if passed string matches its reverse string.
bool isPalindrome(char* str) {
  
  int size = strlen(str); 
  char temp[size];
  int j = 0; int k = 0; int i;
  //store string's reverse in temporary string
	for (i = size-1; i>=0; i--) {
			temp[j] = str[i];
      j++;
	}
  //compare original string and its reverse string.
  while(k<size){
    if (temp[k] != str[k]){
      return false;
    }
    k++;
  }
  return true;
}

int main(void) {
  char string[100];
  printf("Enter string: ");
  gets(string);
  //convert all char to lowercase:
  int i =0;
  while(string[i]!='\0'){
    if(string[i]<='Z'&& string[i]>='A'){
    string[i]=string[i]+32;
  }
    i++;
  }
  
  if(isPalindrome(string)){
    printf("True: This string IS palindrome\n");
  }else{
     printf("False: This string IS NOT palindrome\n");
  }
  
  return 0;
}
