#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 20
#warning Call Initialize

typedef struct{
	int arr[MAX];
	int front, rear;
} priority_queue;

void insert(priority_queue*, int);
void display(priority_queue);
int delete(priority_queue*);
void initialize(priority_queue*);
int empty(priority_queue*);
int full(priority_queue*);

void initialize(priority_queue* pqp){
	pqp->front = pqp->rear = -1;
}

int full(priority_queue* pqp){
	return (pqp->rear + 1) % MAX == pqp->front;
}

int empty(priority_queue* pqp){
	return pqp->front == -1 && pqp->rear == -1;
}

void insert(priority_queue* pqp, int val){
	if(full(pqp)){
		puts("\nOverflow! Cannot insert further elements");
	}
	else if(empty(pqp)){
		pqp->front = pqp->rear = 0;
		pqp->arr[0] = val;
	}
	else{
		int i;
		pqp->rear = (pqp->rear + 1) % MAX;
		for(i = pqp->front; i != pqp->rear; i = (i + 1) % MAX){
			if(pqp->arr[i] > val){
				break;
			}
		}
		
		for(int j = i; j != pqp->rear; j = (j + 1) % MAX){
			int tmp = pqp->arr[j];
			pqp->arr[j] = val;
			val = tmp;
		}
		pqp->arr[pqp->rear] = val;
	}
}

int delete(priority_queue* pqp){
	int val = -1;
	if(empty(pqp)){
		puts("\nUnderflow! Cannot delete further elements");
	}
	else if(pqp->front == pqp->rear){
		val = pqp->arr[pqp->front];
		initialize(pqp);
	}
	else{
		val = pqp->arr[pqp->front];
		pqp->front = (pqp->front + 1) % MAX;
	}
	return val;
}

void display(priority_queue pq){
	if(empty(&pq)){
		puts("Priority Queue is empty");
	}
	else{
		puts("Priority Queue is:");
		for(int i = pq.front; i != pq.rear; i = (i + 1) % MAX){
			printf("%d ", pq.arr[i]);
		}
		printf("%d\n", pq.arr[pq.rear]);
	}
}
