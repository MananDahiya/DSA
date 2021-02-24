#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct node{
	int reg;
	char arr[MAX];
	struct node *prev, *next;
}NODE;

void initialize(NODE* p){
	p->prev = p->next = p;
}

NODE* create(NODE* ptr){
	NODE* tmp = (NODE*)malloc(sizeof(NODE));
	tmp->next = ptr->next;
	tmp->prev = ptr;
	ptr->next = tmp;
	tmp->next->prev = tmp;
	return tmp;
}

NODE* build(){
	NODE* w = (NODE*)malloc(sizeof(NODE));
	initialize(w);
	printf("Enter Number of elements: ");
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		NODE* tmp = create(w->prev);
		printf("\nElement Number %d)\n", i + 1);
		printf("Enter regesteration number: ");
		scanf("%d", &tmp->reg);
		printf("Enter name: ");
		scanf("%s", tmp->arr);
	}
	return w;
}

void display(NODE* w, char* s){
	printf("%s ", s);
	NODE* ptr = w->next;
	if(ptr == w)
		printf("nil");
	while(ptr != w){
		printf("{%d, %s}", ptr->reg, ptr->arr);
		if(ptr->next != w){
			printf(", ");
		}
		ptr = ptr->next;
	}
	printf("\n");
}

int equal(NODE* a, NODE* b){
	NODE *p = a->next, *q = b->next;
	while(p != a){
		if(p->reg != q->reg || strcmp(p->arr, q->arr) != 0)
			return 0;
		p = p->next;
		q = q->next;
	}
	return q == b;
}

void reverse(NODE* a, NODE* b){
	NODE* ptr = b->next;
	while(ptr != b){
		NODE* tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	initialize(b);
	
	ptr = a;
	do{
		NODE* tmp = ptr->next;
		ptr->next = ptr->prev;
		ptr->prev = tmp;
		ptr = tmp;
	}while(ptr != a);
}

NODE* concatenate(NODE* a, NODE* b){
	NODE* w = (NODE*)malloc(sizeof(NODE));
	initialize(w);
	
	int t = 0;
	NODE* p = a->next, *q = b->next;
	while(p != a && q != b){
		NODE* tmp = create(w->prev);
		if(t == 0){
			tmp->reg = p->reg;
			strcpy(tmp->arr, p->arr);
			p = p->next;
		}
		else{
			tmp->reg = q->reg;
			strcpy(tmp->arr, q->arr);
			q = q->next;
		}
		t ^= 1;
	}
	
	while(p != a){
		NODE* tmp = create(w->prev);
		tmp->reg = p->reg;
		strcpy(tmp->arr, p->arr);
		p = p->next;
	}
	
	while(q != b){
		NODE* tmp = create(w->prev);
		tmp->reg = q->reg;
		strcpy(tmp->arr, q->arr);
		q = q->next;
	}
	
	return w;
}
	

int main(){
	puts("wordList1:");
	NODE* wordList1 = build();
	puts("\nwordList2:");
	NODE* wordList2 = build();
	
	display(wordList1, "wordList1:");
	display(wordList2, "wordList2:");
	puts("");
	if(equal(wordList1, wordList2)){
		puts("Equality: 1");
		reverse(wordList1, wordList2);
		display(wordList1, "wordList1:");
		display(wordList2, "wordList2:");
	}
	else{
		puts("Equality: 0");
		display(concatenate(wordList1, wordList2), "concatenateList:");
	}
}
		
