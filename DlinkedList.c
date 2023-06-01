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


ListNode *linearSearch(int key);

ListNode *createListNode(int data)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->value = data;
    temp->next = NULL;
    temp->prev = NULL;
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
        head->prev = temp;
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
    loc->next->prev = temp;

    loc->next = temp;
    temp->prev = loc;
    temp = NULL;
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
        temp->prev = tail;
        tail = tail->next;
        temp = NULL;
    }
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
    if(head==NULL) return;

    ListNode* temp = head;
    head = head->next;
    temp->next = NULL;
    head->prev = NULL;
    free(temp);

    if(head==NULL) tail = NULL;
}


void deleteMiddle(int data)
{
    ListNode* loc = linearSearch(data);
    if(loc==NULL) return;

    loc->prev->next = loc->next;
    loc->next->prev = loc->prev;
    loc->prev = loc->next = NULL;
    free(loc);
}


void deleteLast()
{
    if(tail==NULL) return;
    else if(head==tail)
    {
        free(tail);
        head = tail = NULL;
    }
    else
    {
        ListNode* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
}

int findMiddleElement()
{
    ListNode* hare = head;
    ListNode* tortoise = head;
    while(hare->next!=NULL && hare->next->next!=NULL)
    {

        hare = hare->next->next;
        tortoise = tortoise->next;
    }
    return tortoise->value;
}

int main()
{
    for(int i=10; i<=110; i+=10)
        insertFirst(i);

    printList();

    deleteFirst();
    printList();

    deleteLast();
    printList();

    deleteMiddle(50);
    printList();

    deleteMiddle(55);
    printList();

    printf("Middle Element: %d\n", findMiddleElement());
    return 0;
}