#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node{
	int val;
	struct node* next, *prev;
}NODE;

NODE* create(int x){
	NODE* tmp = (NODE*)malloc(sizeof(NODE));
	tmp->val = x;
	tmp->prev = tmp->next = tmp;
	return tmp;
}

void insert(int d, NODE* head){
	assert(d/10 == 0 && d >= 0);
	NODE* ret = create(d);
	ret->next = head;
	ret->prev = head->prev;
	head->prev->next = ret;
	head->prev = ret;
}

void display(NODE* head, char s[]){
	printf("\n%s\n", s);
	NODE* ptr = head->next;
	while(ptr != head){
		printf("%d", ptr->val);
		ptr = ptr->next;
	}
	puts("");
}

NODE* ADD(NODE* a, NODE* b){
	NODE* head = create(-1);
	NODE *pa = a->prev, *pb = b->prev;
	int carry = 0;
	while(carry || pa != a || pb != b){
		int sum = carry;
		if(pa != a){
			sum += pa->val;
			pa = pa->prev;
		}
		if(pb != b){
			sum += pb->val;
			pb = pb->prev;
		}
		
		int d = sum % 10;
		carry = sum / 10;
		
		insert(d, head->next);
	}
	return head;
}

void build(NODE** head, char s[]){
	printf("\n%s\n", s);
	*head = create(-1);
	char ch;
	while(1){
		scanf("%c", &ch);
		if(ch < '0' || ch > '9') break;
		insert(ch - '0', *head);
	}
}
	

int main(){
	NODE *a, *b;
	build(&a, "Enter First Number:");
	build(&b, "Enter Second Number:");
	display(a, "First Number is: ");
	display(b, "Second Number is: ");
	display(ADD(a, b), "Additon of the two numbers is: ");
	
}
