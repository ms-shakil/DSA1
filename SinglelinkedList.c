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
    free(temp);

    if(head==NULL) tail = NULL;
}

ListNode* prevLoc(int data)
{
    ListNode* frontLeg = head;
    ListNode* backLeg = NULL;
    while(frontLeg!=NULL)
    {
        if(frontLeg->value==data)
            return backLeg;
        backLeg = frontLeg;
        frontLeg = frontLeg->next;
    }
    return NULL;
}

void deleteMiddle(int data)
{
    ListNode* pLoc = prevLoc(data);
    if(pLoc==NULL) return;
    ListNode* temp = pLoc->next;
    pLoc->next = temp->next;
    temp->next = NULL;
    free(temp);
}


void deleteLast()
{
    if(tail==NULL) return;

    ListNode* pLoc = prevLoc(tail->value);
    if(pLoc==NULL)
    {
        free(tail);
        head = tail = NULL;
    }
    else
    {
        pLoc->next = NULL;
        free(tail);
        tail = pLoc;
        pLoc = NULL;
    }
}

void reverseList()
{
     ListNode* firstLeg = head;
     ListNode* secondLeg = NULL;

     while(firstLeg!=NULL){
        ListNode* temp = firstLeg;
        firstLeg = firstLeg->next;
        temp->next = secondLeg;
        secondLeg = temp;
     }
     ListNode* temp = head;
     head = tail;
     head = temp;
     return;
}



void SelectionSort()
{
    for(ListNode* indicator=head; indicator->next!=NULL; indicator=indicator->next)
    {
        int minimum = indicator->value;
        ListNode* minIndex = indicator;
        for(ListNode* j=indicator->next; j!=NULL; j=j->next)
        {
            if(j->value<minimum)
            {
                minimum = j->value;
                minIndex = j;
            }
        }

        int temp = indicator->value;
        indicator->value = minIndex->value;
        minIndex->value = temp;
    }
    return;
}


// void insertInSortedPosition(int data)
// {
//     if(data<=head->value) insertFirst(data);
//     else if(data>=tail->value) insertLast(data);
//     else
//     {
//         ListNode* loc = NULL;
//         for(ListNode* i = head; i!=NULL; i=i->next)
//         {
//             if(i->value<=data) loc = i;
//             else break;
//         }
//         ListNode* temp = createListNode(data);
//         temp->next = loc->next;
//         loc->next = temp;
//         loc = NULL;
//     }
// }




int main()
{
    for(int i=100; i>=10; i-=10)
        insertLast(i);

    printList();

    deleteFirst();
    printList();

    deleteLast();
    printList();

    deleteMiddle(50);
    printList();

    deleteMiddle(55);
    printList();

    // reverseList();
    // printList();

    // SelectionSort();
    // printList();
    return 0;
}