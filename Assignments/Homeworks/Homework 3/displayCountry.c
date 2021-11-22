#include <stdio.h>
#include <string.h>
/***
Author: Aleeza Iftikhar
Homework 4: Part 3 - Question 5
***/

//Struct to store country and codes
struct country_codes{
  char *country;
  int phone_code;
};

//declare function
void displayCountry(int, struct country_codes *Phone_book);

//main class
int main(void) {
  int input;
  //Array of struct to store values of 20 countries and their corresponding international dialing codes in 2D fashion
  struct country_codes Phone_book[20] = { {"Mexico", 52}, {"Iran", 98}, {"Italy", 39}, {"Japan", 81}, {"Norway", 47}, {"Iceland", 354}, {"Czech republic", 420}, {"Estonia", 372}, {"United States", 1}, {"Vietnam", 84}, {"Turkey", 90}, {"United Kingdom", 44}, {"China", 86}, {"India", 91}, {"Pakistan", 92}, {"Egypt", 20}, {"France", 33}, {"Bangladesh", 880}, {"Russia", 7}, {"Spain", 34}};

  printf("Enter an international dialing code: ");
  scanf("%d", &input);

  //calling function
  displayCountry(input, Phone_book);

  return 0;
}

//Function to display country of passed international dialing code in Phone_book
void displayCountry(int input, struct country_codes *Phone_book){
  int i;
  for(i=0; i < 20; i++) {
    if (input == Phone_book[i].phone_code){
      printf("\nArray_index # %d\nDialing_code: %d\nCountry: %s\n",i,Phone_book[i].phone_code,Phone_book[i].country);
      break;
    }else if(i==19){
      printf("\nError: This Phonebook does not contain this international code.\n");
    }
  }
}
