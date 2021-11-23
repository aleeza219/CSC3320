#include <stdio.h>

int main(void) {
  FILE *file;
  file = fopen("test.txt", "r");
  char character[10000];
  int count[26]={0};
  char a;
  //testing
  // printf("\n%d", ('t' - 'a') );
  // printf("\na = %d", ('a') );
  // printf("\nA = %d", ('A') );
  // printf("\n%c", (19 + 'a') );
  // printf("\n%c\n", ('A'+32) );

  while((a = fgetc(file)) != EOF){
  //printing current file
  printf("%c", a );
  //convert all char to lowercase
  if(a<='Z'&& a>='A'){
    a=a+32;
  }
  //store each char count in count array
  if(a<='z'&& a>='a'){
    count[a-'a']++;
  }

  }
int i;
  //find max index counted char
  int maxcount = count[0];
  int maxindex = 0;
  for ( i=1;i<26;i++){
    if(count[i]>maxcount){
      maxcount = count[i];
      maxindex=i;
    }

  }

  printf("\n\nMAX counted letter is '%c' and total count is '%d'", (maxindex + 'a'), maxcount);



  return 0;
}

