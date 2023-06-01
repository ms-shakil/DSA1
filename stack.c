#include<stdio.h>
#include<stdlib.h>

int max =10;

typedef struct 
{
    int top;
    int data[10];
}Stack;
void push(Stack *s ,int val)
{
    if(s->top <max){
      s->data[s->top] = val;
      s->top = s->top +1;

    }else{
        printf("stack is overflow.");
    }
}
int pop(Stack *s){
    int item ;
    if(s->top ==0){
        printf("stack is underflow.");
        return -1;
    }else{
        s->top = s->top -1;
        item =s->data[s->top];
    }
    return item;
}
void printItem(Stack *s){
    for(int i =0;i<s->top;i++){
        printf("%d\n",s->data[i]);
    }
}
int main(){
    Stack my_stack ;
    int item;
    my_stack.top=0;
    push(&my_stack,5);
    push(&my_stack,15);
    push(&my_stack,20);
    pop(&my_stack);
    pop(&my_stack);
    pop(&my_stack);
    pop(&my_stack);


    printItem(&my_stack);
    return 0;
}
