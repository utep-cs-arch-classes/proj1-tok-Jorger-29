#include <stdio.h>
#include "tokenizer.c"

#define SIZE 100


void main(){
  putchar('>');
  
  char token[SIZE];
  int input;  
  int counter = 0;
  
  while((input = getchar()) != '\n' && counter < SIZE-1){
    token[counter++] = input;
  }
  token[counter++] = '\0';

  for(int i=0;token[i] != '\0';i++){
    putchar(token[i]);
  }
  putchar('\n');
  printf("%d\n", space_char(token[0]));
  printf("%d\n", non_space_char(token[0]));
  int *start = word_start(token);
  printf("Value: %c, Pointer: %p\n", *start, start); 
  int *end = word_end(token); 
  printf("Value: %c, Pointer: %p\n", *end, end); 
  int words = count_words(token);
  printf("%d\n", words);
}
