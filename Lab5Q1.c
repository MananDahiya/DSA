#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX 20

typedef struct{
	char arr[MAX][50];
	int front, rear;
}cq;

void insertcq(cq* p, char s[]){
	if((p->rear + 1) % MAX == p->front){
		puts("\nOverflow! Cannot insert element");
	}
	else if(p->front == -1 && p->rear == -1){
		p->front = p->rear = 0;
		strcpy(p->arr[0], s);
	}
	else{
		p->rear = (p->rear + 1) % MAX;
		strcpy(p->arr[p->rear], s);
	}
}

void deletecq(cq* p){
	if(p->front == -1 && p->rear == -1){
		puts("\nUnderflow! Cannot delete element");
	}
	else if(p->front == p->rear){
		p->front = p->rear = -1;
	}
	else{
		p->front = (p->front + 1) % MAX;
	}
}

void displaycq(cq q){
	if(q.front == -1 && q.rear == -1){
		puts("\nCircular Queue is empty");
	}
	else{
		puts("\nContents of Circular Queue are:");
		for(int i = q.front; i != q.rear; i = (i + 1) % MAX){
			printf("%s\t", q.arr[i]);
		}
		printf("%s\n", q.arr[q.rear]);
	}
}

int main(){
	cq q;
	q.front = q.rear = -1;
	
	displaycq(q);
	
	insertcq(&q, "A");
	insertcq(&q, "B");
	insertcq(&q, "ABCD");
	
	displaycq(q);
	
	deletecq(&q);
	displaycq(q);
	
	deletecq(&q);
	displaycq(q);
	
	deletecq(&q);
	displaycq(q);
	
	deletecq(&q);
	displaycq(q);
}
