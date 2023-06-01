#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int value;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode *head = NULL;
ListNode *tail = NULL;


ListNode *linearSearch(int key);

ListNode *createListNode(int data)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->value = data;
    temp->next = NULL;
    return temp;
}

void insertFirst(int data)
{
    if(head==NULL)
    {
        head = createListNode(data);
        tail = head;
    }
    else
    {
        ListNode* temp = createListNode(data);
        temp->next = head;
        head = temp;
        temp = NULL;
    }
}

void insertMiddle(int insertAfter, int data)
{
    ListNode* loc = linearSearch(insertAfter);

    if(loc==NULL) return;

    ListNode* temp = createListNode(data);
    temp->next = loc->next;
    loc->next = temp;
}


void insertLast(int data)
{
    if(head==NULL)
    {
        head = createListNode(data);
        tail = head;
    }
    else
    {
        ListNode* temp = createListNode(data);
        tail->next = temp;
        tail = tail->next;
        temp = NULL;
    }
}

void printList()
{
    for(ListNode* i=head; i!=NULL; i=i->next)
    {
        printf("%d ", i->value);
    }
    printf("\n");
    return;
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

void deleteFirst()
{
 if(head==NULL){
    printf("List is empty.");

  } else  if(head->next ==NULL){
    head =NULL;
    tail = NULL;
  }else{
    ListNode* temp = head->next;
    head = temp;
  
  }

}

void deleteLast()
{
 ListNode* prev ;

 if(head==NULL){
    printf("List is empty.");
 } else if(head->next ==NULL){
    head = NULL;
    tail = NULL;
 }else{

    ListNode* tmp = head;
    while(tmp->next != NULL){
         prev = tmp;
         
         tmp = tmp->next;
    }
    
    prev->next = NULL;
    tail = prev;
    
 }  


}

void deleteMiddle(int data)
{
    ListNode* Findval = linearSearch(data);
    if(Findval->next ==NULL ){
        printf("Next is empty\n");
    }
    else{
    ListNode * val = Findval->next->next;
    Findval->next = val;
    }

}

int main()
{
    for(int i=10; i<=100; i+=10)
        insertFirst(i);

    deleteFirst();
    printList();

    deleteLast();
    printList();

    deleteMiddle(50);
    printList();

    return 0;
}