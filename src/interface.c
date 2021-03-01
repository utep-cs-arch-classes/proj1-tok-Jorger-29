#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.c"

#define SIZE 100


void main(){
  putchar('>');
  
  char *token = (char *)malloc(SIZE);
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
  char *start = word_start(token);
  printf("Value: %c, Pointer: %p\n", *start, start); 
  char *end = word_end(token); 
  printf("Value: %c, Pointer: %p\n", *end, end);
  char words = count_words(token);
  printf("%d\n", words);
  char *copy = copy_str(token, 4);
  printf("%s\n",copy);
  char **arr = (char **)malloc(sizeof(char *) * (2+1));
  arr[2] = '\0';
  char s0[] = "First";
  arr[0] = s0;
  char s1[] = "Test";
  arr[1] = s1;  
  print_tokens(arr);
  free_tokens(arr);
  printf("%s\n", arr[1]);
}
