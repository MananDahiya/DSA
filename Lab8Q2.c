#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}NODE;

NODE* create(int val){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

NODE* insert(NODE* cur, int key){
	if(cur == NULL){
		return create(key);
	}
	
	if(key < cur->data){
		cur->left = insert(cur->left, key);
	}
	else{
		cur->right = insert(cur->right, key);
	}
	
	return cur;
}

void inorder(NODE* root){
    if(root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

NODE* delete(NODE* root, int key){
	if(root == NULL){
		return root;
	}
	
	if(key < root->data){
		root->left = delete(root->left, key);
		return root;
	}
	else if(key > root->data){
		root->right = delete(root->right, key);
		return root;
	}
	
	if(root->left == NULL){
		NODE* tmp = root->right;
		free(root);
		return tmp;
	}
	else if(root->right == NULL){
		NODE* tmp = root->left;
		free(root);
		return tmp;
	}
	
	NODE* par = root;
	NODE* cur = root->right;
	while(cur->left){
		par = cur;
		cur = cur->left;
	}
	
	if(par != root){
		par->left = cur->right;
	}
	else{
		par->right = cur->right;
	}
	
	root->data = cur->data;
	free(cur);
	return root;
}

int menu(){
	printf("\nMenu\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Inorder List\n");
	printf("4. Exit\n");
	printf("Enter Your choice: ");
	int choice;
	scanf("%d", &choice);
	return choice;
}

int main(){
	NODE* root = NULL;
	int choice;
	do{
		choice = menu();
		if(choice == 1){
			int val;
			printf("Enter Number to be inserted: ");
			scanf("%d", &val);
			root = insert(root, val);
		}
		else if(choice == 2){
			int val;
			printf("Enter Number to be deleted: ");
			scanf("%d", &val);
			root = delete(root, val);
		}
		else if(choice == 3){
			printf("Inorder List is:\n");
			inorder(root);
			printf("\n");
		}
		else if(choice == 4){
			printf("Exiting...\n");
		}
		else{
			printf("Entered Choice Invalid! Please try again\n");
		}
	}while(choice != 4);
}
