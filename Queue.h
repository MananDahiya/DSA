#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 20
#warning Call Initialize

typedef struct{
	int arr[MAX];
	int front, rear;
} queue;

void insert(queue*, int);
void display(queue);
int delete(queue*);
void initialize(queue*);
int empty(queue*);
int full(queue*);

void initialize(queue* qp){
	qp->front = qp->rear = -1;
}

int full(queue* qp){
	return qp->rear == MAX - 1;
}

int empty(queue* qp){
	if(qp->front == -1){
		assert(qp->rear == -1);
		return 1;
	}
	return 0;
}


void insert(queue* qp, int val){
	if(full(qp)){
		puts("\nOverflow! Cannot insert further elements");
	}
	else{
		qp->arr[++qp->rear] = val;
		if(qp->front == -1){
			qp->front = 0;
		}
	}
}

int delete(queue* qp){
	int val = -1;
	if(empty(qp)){
		puts("\nUnderflow! Cannot delete further elements");
	}
	else{
		val = qp->arr[qp->front++];
	}
	
	if(qp->front > qp->rear){
		qp->front = qp->rear = -1;
	}	
	return val;
}

void display(queue q){
	if(q.front == -1 && q.rear == -1){
		puts("Queue is Empty!");
	}
	else{
		puts("Queue is:");
		for(int i = q.front; i <= q.rear; i++){
			printf("%d ", q.arr[i]);
		}
		puts("");
	}
}
	
