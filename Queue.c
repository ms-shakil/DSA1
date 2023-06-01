#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int value;
    struct Queue *next;
};

typedef struct Queue Queue;

Queue *head = NULL;
Queue *tail = NULL;

Queue *creatQueue(int data)
{
    Queue *temp = (Queue *)malloc(sizeof(Queue));
    temp->value = data;
    temp->next = NULL;
    return temp;
}

void Enqueue(int val){
    if(head== NULL){
        head = creatQueue(val);
        tail = head;
    }else{
        Queue *temp = creatQueue(val);
        tail->next = temp;
        tail = tail->next;
        temp = NULL;
    }
}

void printList()
{
    for(Queue* i=head; i!=NULL; i=i->next)
    {
        printf("%d ", i->value);
    }
    printf("\n");
    return;
}

int  Dequeue(){
    int val;
    if(head == NULL){
        printf("Queue is underflow.");
        return -1;
    }else if(head->next = NULL){
        val = head->value;
        head = NULL;
        tail = NULL;
        return val;
    }else{
        val = head->value;
        Queue *temp = head;
        head = head->next;
        temp->next=NULL;
        free(temp);
        return val;
    }
}

int main(){
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
        Enqueue(40);

     printList();
     printf("%d\n",Dequeue());
     printf("%d",Dequeue());
 
      return 0;
}