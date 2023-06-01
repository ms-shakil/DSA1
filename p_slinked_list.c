#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int value;
    struct  ListNode *next;
    
};

typedef struct ListNode ListNode;


ListNode *head = NULL;
ListNode *tail = NULL;

ListNode *creatListNode(int val){

    ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
          temp->value = val;
          temp->next = NULL;
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
    if(head==NULL){
        head = creatListNode(val);
        tail = head;
    }else{
        ListNode *temp = creatListNode(val);
        temp->next = head ;
        head = temp;
        temp = NULL;
    }
}

void insertMid(int aft,int val){
    ListNode  *loc = linearSearch(aft);
    if(loc != NULL){
        ListNode  *temp = creatListNode(val);
        temp->next =loc->next;
        loc->next = temp;

    }
}
void insertLast(int val){
    if(head ==NULL){
        head = creatListNode(val);
        tail = head;
    }else{
        ListNode *temp = creatListNode(val);
        tail->next = temp;
        tail = temp;
        temp = NULL;
    }
}

void deleteFirst(){
    if(head->next ==NULL){
        head = tail = NULL;
    }else{
        head = head->next;
    }
}
void deleteLast(){
    if(head->next ==NULL){
        head = tail = NULL;
    }else{
        ListNode *temp = head;
        ListNode *prev = NULL;
        while(temp->next != NULL){
           prev = temp;
           temp= temp->next;
           
        }
        prev->next = NULL;
        tail = prev;
    }
}
void deletemid(int val){
    ListNode *temp =head;
   ListNode *prev =NULL;
    while (temp->value != val){
          prev = temp;
          temp= temp->next;
    }
    
    prev->next= prev->next->next;
}
void ListPrint(){
    ListNode *temp = head;
    while(temp->next != NULL){
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("%d",temp->value);
}
void reverseList(){
    ListNode *F = head;
    ListNode *S = NULL;
    while (F != NULL){
        ListNode * tmp = F;
        F = F->next;
        tmp->next =S;
        S = tmp;
        
    }
    ListNode * temp = head;
    head = tail;
    tail = temp;
    return;
    
}
void selection_sort(){
    for(ListNode *ind = head;ind->next !=NULL;ind=ind->next){
        for(ListNode *j = ind->next;j !=NULL;j=j->next){
            if(ind->value > j->value){
               int temp =ind->value;
               ind->value = j->value;
               j->value = temp;
            }
        }
    }
}
int main(){
    insertFirst(60);
    insertFirst(20);
    insertFirst(100);
    insertFirst(30);
    insertFirst(66);
    insertFirst(70);

    ListPrint();
    selection_sort();
    printf("\n");
    ListPrint();
  return 0;
}