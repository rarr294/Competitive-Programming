#include <stddef.h>
#include <stdlib.h>

struct LinkedList {
  struct LinkedList *next;
  int value;
};

int *linked_list_to_array(const struct LinkedList *list, size_t *length){
  struct LinkedList *list_cp = list;

  *length = 0;
  while((*length = *length + 1),(list = list->next)){}

  int *mem = malloc((*length) * 4);

  int index = 0;
  while(
   (mem[index++] = list_cp->value),
   (list_cp = list_cp->next)
   ){}

  return mem;
}
