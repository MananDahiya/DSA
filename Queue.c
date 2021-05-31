#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#warning Call initilize before using Queue

typedef struct node{
  int data;
  struct node* next;
}node;

node* build(int val){
  node* cur = malloc(sizeof(node));
  cur -> data = val;
  cur -> next = NULL;
  return cur;
}

typedef struct queue{
  int size;
  node *front, *end;
}queue;

int empty(queue* q){
  return q -> size == 0;
}

void push(node* add, queue* q){
  if(q -> front == NULL){
    q -> front = q -> end = add;
  }
  else{
    q -> end -> next = add;
    q -> end = add;
  }
  q -> end -> next = NULL;
  q -> size++;
}

void pop(queue* q){
  assert(!empty(q));
  q -> front = q -> front -> next;
  if(q -> front == NULL)
    q -> end = NULL;
  q -> size--;
}

node front(queue* q){
  assert(!empty(q));
  return *q -> front;
}

node back(queue* q){
  assert(!empty(q));
  return *q -> end;
}

void display(queue* q){
  node* it = q -> front;
  while(it){
    printf("%d ", it -> data);
    it = it -> next;
  }
  puts("");
}

int size(queue* q){
  return q -> size;
}

void initilize(queue* q){
  q -> front = q -> end = NULL;
  q -> size = 0;
}

/*
NOTE: 
* front() and back() return node, and not the value
* Changes if different type of data needs to be stored in queue
1) node   2) build    3) push   4) display    5) initialize
*/

int main(){
  queue* q = (queue*) malloc(sizeof(queue));
  initilize(q);
}
