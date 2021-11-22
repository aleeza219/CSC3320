#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*************
Author: Aleeza Iftikhar
Homwoerk 4: Part 1 - Question 2
Program: to check password safety entered by user
*************/
void checkPasswd2(char* password){
 int length = strlen(password);
  int deduction = 0;

 //If password length is less than 10, program will deduct safety points
  if (length<10){
    int temp = 10-length; //num Of missing characters
    deduction = temp*5; //deduct 5 points per missing character
  }

  int i=0;
  int num=0;
  int upper=0;
  int lower=0;
  int consecFound=0;
  //go through each character of password string
  while(i<length){
    if(isdigit(password[i])){//check if password contains number
      num++;
    }
    if(isupper(password[i])){//check if passowrd contains uppercase letter
      upper++;
    }
    if(islower(password[i])){//check if passowrd contains lowercase letter
      lower++;
    }
//check once, if more than 2 consecutive chars present such as 123456 or abc.
    if(i>=2 && password[i] == password[i-1]+1 && password[i] == password[i-2]+2){
      consecFound = 1;
    }
    i++;
  }

  if(num==0){//deducting points if number not found
    deduction+=20;
  }
  if(upper==0){//deducting points if capital letter not found
    deduction+=20;
  }
  if(lower==0){//deducting points if small letter not found
    deduction+=20;
  }
  if(consecFound==1){ //deducting points if consecutive numbers are found
    deduction+=20;
  }

  //Final Output:
  if(deduction>30){//if more than 30 points are deducted, flag user that password is unsafe
    printf("\n%d safety points deducted, The password is unsafe! Please reset.\n", deduction);
  }else{//Otherwise, password is safe.
    printf("\nThe password is safe\n");
  }
}
int main(void) {
  char password[20];
  printf("Enter password: ");
  gets(password);
  checkPasswd2(password);
  return 0;
}
