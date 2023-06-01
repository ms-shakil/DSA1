#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int value;
    struct ListNode *next;
    struct ListNode *prev;
};

typedef struct ListNode ListNode;

ListNode *head = NULL;
ListNode *tail = NULL;

ListNode *creatListNode(int val){
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp ->value = val;
    temp ->next = NULL;
    temp ->prev = NULL;
    return temp;
}
ListNode *linearSearch(int key)
{
    for(ListNode* i=head; i!=NULL; i=i->next)
    {
        if(i->value==key)
            return i;
    }
    return NULL;
}

void insertFirst(int val){
    if(head == NULL){
        head = creatListNode(val);
        tail = head;
    }else{
        ListNode *temp = creatListNode(val);
        temp->next = head;
        head ->prev =temp;
        head = temp;
        temp = NULL; 
    }
}

void insertLast(int val){
     if(head == NULL){
        head = creatListNode(val);
        tail = head;
     }else{
        ListNode *temp = creatListNode(val);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        temp = NULL;
     }
}
void insertMiddle(int aft,int val){
    ListNode  *loc = linearSearch(aft);
    if(loc == NULL){
        printf("empty list");
    }else{
        ListNode *temp = creatListNode(val);
         temp->next =loc->next;
         loc->next->prev = temp;
         loc->next =temp;
         temp->prev= loc;
         temp= NULL;
    }
}
void deleteFirst(){
    if(head == NULL){
        return;
    }
    ListNode *temp = head;
    head = head->next;
    temp->next = NULL;
    head->prev = NULL;
    free(temp);
    if(head == NULL) tail == NULL;
}
void deleteLast(){
    if(tail == NULL) return;
    if(head == tail){
        free(tail);
        head =NULL;
        tail = NULL;
    }else{
        ListNode *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
}
void deleteMiddle(int val){
    ListNode  *loc = linearSearch(val);
    if (loc == NULL)return;
    loc->prev->next =loc->next;
    loc->next->prev = loc->prev;
    loc->next=loc->prev = NULL;
    free(loc);
}
void printList()
{
    printf("List: ");
    for(ListNode* i=head; i!=NULL; i=i->next)
    {
        printf("%d ", i->value);
    }
    printf("\n");
    return;
}
int main(){

    insertFirst(10);
    insertFirst(20);
    insertLast(30);
    insertMiddle(20,15);
    printList();
    deleteFirst();
    printList();
    deleteLast();
    printList();
    deleteMiddle(15);
    printList();
    return 0;
}