/*
 * code.c:
 *      blinks the LED perhipheral
 *      Abdou Sarr | Winter 2017
 */
 
#include <stdio.h>
#include <wiringPi.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}
 
int main(void) {

  printf ("Program Initialized\n");

  node_t * head = NULL;
  head = malloc(sizeof(node_t));
  if (head == NULL) {
      return 1;
  }

  head->val = 1;
  head->next = NULL;

  push(head, 0);
  push(head, 1);
  push(head, 0);
  push(head, 1);
 
  if (wiringPiSetup () == -1) {
    return 1;
  }
 
  pinMode (0, OUTPUT); // perhipheral pin
 
  node_t * current = head;

  for(;;) {
    digitalWrite (0, current->val);
    delay (500);
    current = current->next;
  }
  
  return 0;
}
