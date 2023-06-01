#include<stdio.h>
#include<stdlib.h>

int max =5;

typedef struct 
{
    int tail;
    int head;
    int data[5];
}Queue;
void Enqueue(Queue *s ,int val)
{
    if(s->tail <max){
      s->data[s->tail] = val;
      s->tail = s->tail +1;

    }else{
        printf("stack is overflow.\n");
    }
}
int Dequeue(Queue *s){
    int item ;
    if(s->tail ==s->head){
        printf("stack is underflow.\n");
        return -1;
    }else{
        item =s->data[s->head];
        s->head = s->head +1;
    }
    return item;
}
void printItem(Queue *s){
    for(int i = s->head;i<s->tail;i++){
        printf("%d\n",s->data[i]);
    }
}
int main(){
    Queue my_Queue ;
    int item;
    my_Queue.head=0;
    my_Queue.tail = 0;
    Enqueue(&my_Queue,1);
    Enqueue(&my_Queue,2);
//     Enqueue(&my_Queue,3);
//     Enqueue(&my_Queue,5);
//     Enqueue(&my_Queue,6);
//    Enqueue(&my_Queue,6);
//    Enqueue(&my_Queue,9);
   Enqueue(&my_Queue,10);
    Dequeue(&my_Queue);
    Dequeue(&my_Queue);
    Dequeue(&my_Queue);
    Dequeue(&my_Queue);


    // printItem(&my_Queue);
    return 0;
}
