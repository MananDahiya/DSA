#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node{
    int x;
    struct node* next;
}NODE;

typedef struct{
    NODE *front, *rear;
}Queue;

void initialize(Queue* q){
    q->front = q->rear = NULL;
}

void insert(Queue* q, int val){
    NODE* tmp = (NODE*)malloc(sizeof(NODE));
    tmp->x = val;
    tmp->next = NULL;
    if(q->front == NULL){
        assert(q->rear == NULL);
        q->front = q->rear = tmp;
    }
    else{
        q->rear->next = tmp;
        q->rear = tmp;
    }
}

void delete(Queue* q){
    if(q->front == NULL){
        assert(q->rear == NULL);
        puts("Cannot delete anymore elemments!");
    }
    else{
        NODE* tmp = q->front;
        q->front = q->front->next;
        free(tmp);
        if(q->front == NULL){
            q->rear = NULL;
        }
    }
}

void display(Queue* q){
    if(q->front == NULL){
        puts("Empty Queue");
        return;
    }
    NODE* tr = q->front;
    while(tr){
        printf("%d ", tr->x);
        tr = tr->next;
    }
    puts("");
}

int main(){
    Queue q;
    initialize(&q);

    display(&q);
    insert(&q, 1);
    insert(&q, 2);
    insert(&q, 3);
    insert(&q, 4);
    display(&q);

    delete(&q);
    delete(&q);

    display(&q);

    delete(&q);
    delete(&q);

    display(&q);

    delete(&q);
}
