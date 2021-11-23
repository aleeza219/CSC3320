#include<stdio.h>

void split_time(long, int*, int*, int*);//declaration

int main(){
  long n;
	int hr, min, sec;
	printf("Enter seconds: ");
	scanf("%lu", &n);
	split_time(n, &hr, &min, &sec);
	printf("\nConverted format: %d hour %d mins %d secs", hr, min, sec);
	return 0;
}
	
  void split_time(long total_sec, int *hour, int *minute, int *second){
  *hour = (total_sec/3600); 
	
	*minute = (total_sec -(3600*(*hour)))/60;
	
	*second = (total_sec -(3600**hour)-(*minute*60));
	}
