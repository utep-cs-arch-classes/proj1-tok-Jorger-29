#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *list = (List*)malloc(sizeof(List)*1);
  list->root = (Item*)malloc(sizeof(Item)*1);
  list->root->next = NULL;
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *root = list->root;
  int count = 1;
  while(root->next != NULL){
    root = root->next;
    count++;
  }
  root->next = (Item*)malloc(sizeof(Item)*1);
  root->id = count;
  root->str = str;
  root->next->next = NULL;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
    printf("%d",id);
  Item *root = list->root;
  printf("%d",id);
  int count = 1;
  while(root->next != NULL){
    if(root-> id == id){
      return root->str;
    }else{
      root = root->next;
      count++;
    }
  }
}

/* Print the entire contents of the list. */
void print_history(List *list){
  Item *root = list->root;
  int count = 1;
  while(root->next != NULL){
    char *ptr = root->str;
    printf("%d. ",count);
    for(int i=0; *(ptr+i)!='\0' ; i++){
      putchar(ptr[i]);
    }
    putchar('\n');
    root = root->next;
    count++;
  }
}

/* Free the history list and the strings it references. */
void free_history(List *list){
  Item *root = list->root;
  int count = 1;
  while(root != NULL){    
    root = root->next;
    free(root->str);
    free(root);
  }
}
