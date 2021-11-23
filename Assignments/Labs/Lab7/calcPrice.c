#include <stdio.h>

int main(void) {
  int item, price, qty, amount, mm, dd, yyyy;
  printf("Enter item number: ");
  scanf("%d", &item);
  printf("Enter unit price: ");
  scanf("%d", &price);
  printf("Enter quantity: ");
  scanf("%d", &qty);
  printf("Enter purchase date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &mm, &dd, &yyyy);
  amount = price*qty; 
  printf("Item#\tQuantity\tPurchase Date\tUnit Price\tTotal Amount\n");
  
  printf("%d\t%d\t\t%d/%d/%d\t$%d\t\t$%d\n", item, qty, mm, dd, yyyy, price, amount);

}
