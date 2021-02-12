#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 20
#warning Call Initialize

typedef struct{
	int arr[MAX];
	int rear, front;
}dequeue;

void initialize(dequeue*);
int empty(dequeue*);
int full(dequeue*);
void display(dequeue);
void insert(dequeue*, int, int);
int delete(dequeue*, int);

void initialize(dequeue* dp){
	dp->front = dp->rear = -1;
}

int empty(dequeue* dp){
	if(dp->rear == -1){
		assert(dp->front == -1);
		return 1;
	}
	return 0;
}

int full(dequeue* dp){
	return (dp->rear + 1) % MAX == dp->front;
}

void insert(dequeue* dp, int dir, int val){
	if(empty(dp)){
		dp->front = dp->rear = 0;
		dp->arr[0] = val;
	}
	else if(full(dp)){
		puts("\nOverflow! Cannot insert further elements");
	}
	else if(dir == 1){
		//printf("%d %d\n", dp->front, dp->rear);
		dp->rear = (dp->rear + 1) % MAX;
		dp->arr[dp->rear] = val;
		//printf("%d %d\n", dp->front, dp->rear);
	}
	else{
		dp->front = (dp->front - 1 + MAX) % MAX;
		dp->arr[dp->front] = val;
	}
}

int delete(dequeue* dp, int dir){
	int val = -1;
	if(empty(dp)){
		puts("\nUnderflow! Cannot delete further elements");
	}
	else if(dp->rear == dp->front){
		val = dp->arr[dp->rear];
		initialize(dp);
	}
	else if(dir == 1){
		val = dp->arr[dp->rear];
		dp->rear = (dp->rear - 1 + MAX) % MAX;
	}
	else{
		val = dp->arr[dp->front];
		dp->front = (dp->front + 1) % MAX;
	}
	return val;
}

void display(dequeue d){
	if(empty(&d)){
		puts("Dequeue is empty!");
	}
	else{
		assert(d.front >= 0 && d.rear >= 0);
		puts("Contents of array are:");
		for(int i = d.front; i != d.rear; i = (i + 1) % MAX){
			printf("%d ", d.arr[i]);
		}
		printf("%d", d.arr[d.rear]);
		puts("");
	}
}
