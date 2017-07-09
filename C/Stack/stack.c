#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct ListNode {
  struct ListNode *next;
  char *data;
} ListNode;

bool createStack( ListNode **stack );
bool deleteStack( ListNode **stack );
bool push( ListNode **stack, char *data );
bool pop( ListNode **stack, char **data );
void printStack( ListNode **stack );

bool push( ListNode **stack, char *data ) {
  ListNode *a = malloc( sizeof(ListNode) );
  if (!a) return false;

  a->data = data;
  a->next = *stack;
  *stack = a;
  printf("Push '%s' onto the stack.\n\n", a->data);
  return true;
}

bool pop( ListNode **stack, char **data ) {
  ListNode *a;
  if ( !(a = *stack) ) return false;

  *data = a->data;
  *stack = a->next;
  free(a);
  return true;
}

bool createStack( ListNode **stack ) {
  *stack = NULL;
  printf("Stack created!\n\n");
  return true;
}

bool deleteStack( ListNode **stack ) {
  ListNode *next;
  while( *stack ) {
    next = (*stack)->next;
    free( *stack );
    *stack = next;
  }
  printf("Stack destroyed!\n\n");
  return true;
}

void printStack( ListNode **stack ) {
  ListNode *next = *stack;
  printf("========= STACK =========\n");
  while( next ) {
    printf("%s\n", next->data);
    next = next->next;
  }
  printf("=========================\n\n");
}
