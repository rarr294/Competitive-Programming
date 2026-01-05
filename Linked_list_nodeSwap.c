#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

//Linked List definition
struct Node {
  struct Node *next;
};
//

struct Node *swap_node_pairs(struct Node *head){
  if(head == NULL || head->next == NULL){
    return head;
  }
  
  //count size
  int Stacksize = 0;
  struct Node *ptr = head;
  while(ptr){
    Stacksize++;
    ptr = ptr->next;
  }
  //
  
  ptr = head;
  
  //push to stack
  int index = 0;
  uintptr_t *stack = (uintptr_t*)malloc(sizeof(uintptr_t) * Stacksize);
  while(ptr){
    stack[index] = (uintptr_t)ptr;
    index++;
    ptr = ptr->next;
  }
  //
  
  //swap
  if(Stacksize % 2 == 0){ 
    int a1 = 0;
    for(int a2 = 1;a2 < Stacksize;a2 += 2){
      uintptr_t tmp = stack[a1];
      stack[a1] = stack[a2];
      stack[a2] = tmp;     
      a1 += 2;
    }
    head = (struct Node*)stack[0];
    ptr = head;
    
    for(int a = 1;a < Stacksize;a++){
      ptr->next = (struct Node*)stack[a];
      ptr = ptr->next;
    }
    ptr->next = NULL;
    return head;
  }
  

  Stacksize--;
  struct Node* lastNode = (struct Node*)stack[Stacksize];
  int a1 = 0;
  for(int a2 = 1;a2 < Stacksize;a2 += 2){
      uintptr_t tmp = stack[a1];
      stack[a1] = stack[a2];
      stack[a2] = tmp;     
      a1 += 2;
  }
  head = (struct Node*)stack[0];
  ptr = head;    

  for(int a = 1;a < Stacksize;a++){
    ptr->next = (struct Node*)stack[a];
    ptr = ptr->next;   
  }  
  ptr->next = lastNode;
  //
  
  return head;
}
