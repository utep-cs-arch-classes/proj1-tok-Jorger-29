#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.c"
#include "history.c"

#define SIZE 100

void main(){
  List *list = init_history();
  while(1){
    putchar('>');
    char *token = (char *)malloc(SIZE);
    char input;  
    int counter = 0;
    
    while((input = getchar()) != '\n' && counter < SIZE-1){
      token[counter++] = input;
    }
    if(counter == 1){
      if(token[counter-1] == '+'){
	break;
      }else if(token[counter-1] == '~'){
	print_history(list);
      }
    }else if(counter == 2){
      if(token[counter-2] == '!'){
	char* str = get_history(list, token[counter-1]);
	printf("%s\n",str);
      }
    }else{ 
      token[counter++] = '\0';

      add_history(list, token);
     
      char **arr = tokenize(token); 
      print_tokens(arr);
    }
  }
} 
