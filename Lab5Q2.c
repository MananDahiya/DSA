#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{
	int* arr;
	int n;
	int pos[2][2], limit[2][2];
}TCQ;

//Left - 0, Right - 1

void initialize(TCQ* p, int n){
	p->n = n;
	p->arr = (int*)calloc(n, sizeof(int));
	p->limit[0][0] = 0;
	p->limit[0][1] = p->limit[1][0] = (p->n >> 1);
	p->limit[1][1] = p->n;
	p->pos[0][0] = p->pos[0][1] = p->limit[0][0] - 1;
	p->pos[1][0] = p->pos[1][1] = p->limit[1][0] - 1;
}

int empty(TCQ* p, int t){
	return p->pos[t][0] == p->limit[t][0] - 1 && p->pos[t][1] == p->limit[t][0] - 1;
}

int change(TCQ*p, int t, int i){
	assert(i <= p->limit[t][1]);
	if(i == p->limit[t][1]){
		return p->limit[t][0];
	}
	return i;
}

int full(TCQ* p, int t){
	int L = p->pos[t][0], R = change(p, t, p->pos[t][1] + 1);
	return L == R;
}

void insert(TCQ* p, int t, int val){
	if(full(p, t)){
		puts("\nCannot Insert Element");
	}
	else if(empty(p, t)){
		p->pos[t][0] = p->pos[t][1] = p->limit[t][0];
		p->arr[p->limit[t][0]] = val;
	}
	else{
		p->pos[t][1] = change(p, t, p->pos[t][1] + 1);
		p->arr[p->pos[t][1]] = val;
	}
}

int delete(TCQ* p, int t){
	int ret = -1;
	if(empty(p, t)){
		puts("\nCannot Delete Element");
	}
	else if(p->pos[t][0] == p->pos[t][1]){
		ret = p->arr[p->pos[t][0]];
		p->pos[t][0] = p->pos[t][1] = p->limit[t][0] - 1;
	}
	else{
		ret = p->arr[p->pos[t][0]];
		p->pos[t][0] = change(p, t, p->pos[t][0] + 1);
	}
	return ret;
}

void display(TCQ* p){
	puts("\nContents of Queue are");
	for(int t = 0; t < 2; t++){
		printf("%d)  ", t + 1);
		if(empty(p, t)){
			puts("Queue is empty");
		}
		else{
			for(int i = p->pos[t][0]; i != p->pos[t][1]; i = change(p, t, i + 1)){
				printf("%d ", p->arr[i]);
			}
			printf("%d\n", p->arr[p->pos[t][1]]);
		}
	}
}

int menu(){
	int t;
	puts("\nOptions");
	puts("1.Insert");
	puts("2.Delete");
	puts("3.Display");
	puts("4.Exit");
	printf("Enter your choice: ");
	scanf("%d", &t);
	return t;
}

int main(){
	TCQ q;
	int n, op;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	initialize(&q, n);
	do{
		op = menu();
		switch(op){
			case 1:;
				int val, t;
				printf("Enter 0 for inserting in Left Queue and 1 for inserting in Right Queue: ");
				scanf("%d", &t);
				printf("Enter Value to be inserted: ");
				scanf("%d", &val);
				insert(&q, t, val);
				break;
			
			case 2:
				printf("Enter 0 for inserting in Left Queue and 1 for inserting in Right Queue: ");
				scanf("%d", &t);
				if(!empty(&q, t))
					printf("Element deleted is: %d\n\n", delete(&q, t));
				break;
			
			case 3:
				display(&q);
				break;
			case 4:
				printf("Exiting...\n");
				break;
			
			default:
				printf("Invalid Choice\n");
		}
	}while(op != 4);
}
