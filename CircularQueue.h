#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 4
#warning Call Initialize

typedef struct{
	int arr[MAX];
	int rear, front;
}circular_queue;

void initialize(circular_queue*);
int empty(circular_queue*);
int full(circular_queue*);
void display(circular_queue);
void insert(circular_queue*, int);
int delete(circular_queue*);

void initialize(circular_queue* cqp){
	cqp->front = cqp->rear = -1;
}

int empty(circular_queue* cqp){
	if(cqp->rear == -1){
		assert(cqp->front == -1);
		return 1;
	}
	return 0;
}

int full(circular_queue* cqp){
	return (cqp->rear + 1) % MAX == cqp->front;
}

void insert(circular_queue* cqp, int val){
	if(full(cqp)){
		puts("\nOverflow! Cannot insert further elements");
	}
	else if(empty(cqp)){
		cqp->front = cqp->rear = 0;
		cqp->arr[0] = val;
	}
	else{
		cqp->rear = (cqp->rear + 1) % MAX;
		cqp->arr[cqp->rear] = val;
	}
}

int delete(circular_queue* cqp){
	int val = -1;
	if(empty(cqp)){
		puts("\nUnderflow! Cannot delete further elements");
	}
	else if(cqp->front == cqp->rear){
		val = cqp->arr[cqp->front];
		initialize(cqp);
	}
	else{
		val = cqp->arr[cqp->front];
		cqp->front = (cqp->front + 1) % MAX;
	}
	
	return val;
}

void display(circular_queue cq){
	if(empty(&cq)){
		puts("Circular Queue is empty");
	}
	else{
		puts("Circular Queue is:");
		for(int i = cq.front; i != cq.rear; i = (i + 1) % MAX){
			printf("%d ", cq.arr[i]);
		}
		printf("%d\n", cq.arr[cq.rear]);
	}
}
