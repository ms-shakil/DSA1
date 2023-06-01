#include<stdio.h>
#include<stdlib.h>
int top =-1;
int arr[5];
void push(int val){
    if(5<=top){
        printf("Stack overflow");
    }else{
        top++;
        arr[top]= val;
    }
}

int  Dequeue(){
    int data;
    if(top>=-1){
        printf("stack is under flow");
    }else{
        data = arr[top];
        top--;
        return data;
    }
}
int main(){
    push(5);
    push(50);
    push(10);
    push(33);
    for(int i=0;i<=top;i++){
        printf("%d\n",arr[i]);
    }
   
    printf("pop value is %d",Dequeue());
}