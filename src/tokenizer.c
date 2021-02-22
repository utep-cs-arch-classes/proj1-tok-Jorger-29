#include <stdio.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   (' ', '\t', or '\n').
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c == ' ' || c == '\t' || c == '\n' || c == '\0'){
    return 1;
  }else{
    return 0;
  }
}

/* Return true (non-zero) if c is a non-whitespace
   character (not space, tab, or newline).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  if(c == ' ' || c == '\t' || c == '\n' || c == '\0'){
    return 0;
  }else{
    return 1;
  }
}

/* Returns a pointer to the first character of the next
   space-separated word in zero-terminated str.  Return a zero pointer if
   str does not contain any words.
   str is assumed to be pointing to a space character */
char *word_start(char *str){  
  for(int i=0; *(str+i)!='\0' ; i++){
    if(non_space_char(*(str+i))){
      return str+i;
    }
  }
}

/* Returns a pointer terminator to the first space character or string-terminator
   following str in a zero terminated string.
   str is assumed to be pointing to a non-space character*/
char *word_end(char *str){
  char *start = word_start(str);
  for(int i=0; *(start+i)!='\0'; i++){
    if(space_char(*(start+i+1))){
      return start+i;
    }
  }
}

/* Counts the number of space seperated words in the string argument. */
int count_words(char *str){
  int counter = 0;
  for(int i=0; *(str+i)!='\0' ;	i++){
    if(non_space_char(*(str+i))){
      if(space_char(*(str+i+1))){
	counter++; 
      }
    }
  }
  return counter;
}
