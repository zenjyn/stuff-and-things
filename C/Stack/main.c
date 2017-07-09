#include <stdio.h>
#include "stack.c"

int main() {
  struct ListNode *head;
  createStack( &head );

  push( &head, "Emmett Fitz-hume" );
  push( &head, "Austin Milbarge" );
  printStack( &head );

  char *str;
  pop( &head, &str );
  printf("Popped '%s' from the stack.\n\n", str);
  printStack( &head );

  deleteStack( &head );

  return 0;
}
