#include <stdio.h>
#include <string.h>
/****
Author: Aleeza Iftikhar
Homwoerk 4: Part 1 - Question 1
Program: to check password length entered by user
****/
void checkPasswd(char* password){
  //If password length is less than 10, program will start to deduct safety points
  if (strlen(password)<10){
    int temp = 10-strlen(password); //num Of missing characters

    int deduction = temp*5; //deduct 5 points per missing character
    
    if(deduction>30){//if more than 30 points are deducted, flag user that password is unsafe
        printf("\n%d safety points deducted, The password is unsafe! Please reset.\n", deduction);
    }else{//if some safety points are deducted (less than or equal to 30)
    printf("\nThe password is safe (but %d safety points are deducted)\n", deduction);
    }
  }else{//If passowrd length >= 10
    printf("\nThe passowrd is safe\n");
  }
}
int main(void) {
  char password[20];
  printf("Enter password: ");
  gets(password);
  checkPasswd(password);
  return 0;
}
