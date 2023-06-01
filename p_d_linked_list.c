#include<stdio.h>
#include<stdlib.h>

struct  ListNode{
    int value;
    struct  ListNode *next;
    struct ListNode  *prev;
    
};

typedef struct ListNode ListNode;
ListNode *head ;
ListNode *tail;
ListNode * creatListNode(int val){
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->value = val;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;

}
void insertFirst(int val){
    if(head == NULL){
        head = creatListNode(val);
        tail = head;
    }else{
        ListNode * temp = creatListNode(val);
        temp->next = head;
        head->prev =temp;
        head = temp;
        temp = NULL;
    }
}

void insertLast(int val){
    ListNode * temp = creatListNode(val);
    if(head ==NULL){
        head = tail = temp;
    }else{
        tail->next = temp;
        temp->prev =tail;
        tail = tail->next;
        temp = NULL;
    }
}
  
void insertMiddle(int aft,int val){
    ListNode * loc = head;
    while(loc != NULL){
        if(loc->value == aft){
            break;
        }
        loc=loc->next;
    }
    ListNode *temp = creatListNode(val);
    temp->next =loc->next;
    loc->next->prev = temp;
    loc->next = temp;
    temp->prev = loc;
    temp = NULL;
}  

void deleteFirst(){
    if(head->next == NULL){
        head = tail  = NULL;
    }else{
        head = head->next;
        head->prev = NULL;
    }
}
void deleteLast(){
    if(head->next ==NULL){
        head = tail = NULL;
    }else{
        tail = tail->prev;
        tail->next = NULL;
    }
}

void deleteMiddle(int val){
    ListNode * loc = head;
    while(loc != NULL){
        if(loc->value == val){
            break;
        }
        loc=loc->next;
    }
    loc->prev->next =loc->next;
    loc->next->prev = loc->prev;
}
void ListPrint(){
    ListNode *temp = head;
    while(temp->next != NULL){
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("%d",temp->value);
}
void printReverse(){
    ListNode * temp = tail;
    while(temp->prev != NULL){
        printf("%d ",temp->value);
        temp= temp->prev;
    }
    printf("%d ",temp->value);
}

void reverseList(){
    ListNode * F= head;
    ListNode *S = NULL;
    while (F != NULL){
        ListNode * temp = F;
        F = F->next;
        temp->next = S;
        temp->prev =F;
        S = temp;
    }
    ListNode *ab = head;
    head = tail;
    tail = ab;
    
}

int main(){

    insertFirst(50);
    insertFirst(40);
    insertFirst(20);
    insertFirst(10);
   reverseList();
    ListPrint();
   
    // printReverse();
    return 0;
}  