#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int val;
	struct node* next;
}NODE;

NODE* create(int x){
	NODE* ret = (NODE*)malloc(sizeof(NODE));
	ret->val = x;
	ret->next = NULL;
	return ret;
}

NODE* Intersect(NODE* a, NODE* b){
	NODE* head = create(-1);
	NODE* ptr = head;
	
	a = a->next;
	while(a){
		int x = a->val;
		int add = 0;
		NODE* c = b->next;
		while(c){
			if(c->val == x){
				add = 1;
				break;
			}
			c = c->next;
		}
		if(add){
			ptr->next = create(x);
			ptr = ptr->next;
		}
		a = a->next;
	}
	return head;
}

NODE* Union(NODE* a, NODE* b){
	NODE* head = create(-1);
	NODE* ptr = head;
	
	NODE* c = a->next;
	while(c){
		ptr->next = create(c->val);
		ptr = ptr->next;
		c = c->next;
	}
	
	b = b->next;
	while(b){
		c = a->next;
		int x = b->val;
		int add = 1;
		while(c){
			if(c->val == x){
				add = 0;
				break;
			}
			c = c->next;
		}
		if(add){
			ptr->next = create(x);
			ptr = ptr->next;
		}
		b = b->next;
	}
	return head;
}

void display(NODE* a, char* s){
	printf("\n%s\n", s);
	a = a->next;
	while(a){
		printf("%d ", a->val);
		a = a->next;
	}
	puts("");
}

int main(){
	int n;
	printf("Enter size of first list: ");
	scanf("%d ", &n);
	NODE* h1 = create(-1);
	NODE* p1 = h1;
	
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		p1->next = create(x);
		p1 = p1->next;
	}
	
	printf("Enter size of second list: ");
	scanf("%d ", &n);
	NODE* h2 = create(-1);
	NODE* p2 = h2;
	
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		p2->next = create(x);
		p2 = p2->next;
	}
	
	display(h1, "List 1 is:");
	display(h2, "List 2 is:");
	display(Union(h1, h2), "Union of the two list is:");
	display(Intersect(h1, h2), "Intersection of the two list is:");
}
	
