#include <stdio.h>

int main(void) {

  int a, b, c;

  printf("Enter phone number [(999)999-9999]: ");

  scanf("(%i) %i-%i", &a, &b, &c);

  printf("You entered %i.%i.%i", a, b, c);

  return 0;
}