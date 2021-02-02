#include <stdio.h>

#define SIZE 100

void main(){
  putchar('>');
  
  char token[SIZE];
  int input;  
  int counter = 0;
  
  while((input = getchar()) != '\n'){
    token[counter++] = input;
  }
  token[counter++] = '\0';

  for(int i=0;token[i] != '\0';i++){
    putchar(token[i]);
  }
  putchar('\n');
}
