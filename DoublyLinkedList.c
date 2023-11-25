#include <stdio.h>
#include <stdlib.h>
struct DoublyLinkedList
{
    int key;
    struct DoublyLinkedList *next;
    struct DoublyLinkedList *prev;
};
struct DoublyLinkedList *head = NULL;
int isEmpty()
{
    if(head==NULL) return 1;
    else return 0;
}
void insertionTail(int data)
{
    struct DoublyLinkedList *ptr,*temp;
    ptr = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
    if(ptr==NULL) printf("\nError : Memmory Allocation Failed !");
    else
    {
        ptr->key = data;
        if(isEmpty())
        {
            ptr->next=NULL;
            ptr->prev=NULL;
            head=ptr;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
        printf("\nInserted %d at Tail",data);
    }
}
void insertionHead(int data)
{
    struct DoublyLinkedList *ptr;
    ptr = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
    if(ptr==NULL) printf("\nError : Memmory Allocation Failed !");
    else
    {
        ptr->key = data;
        if(isEmpty())
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            ptr->next = head;
            head->prev = ptr;
            ptr->prev = NULL;
            head = ptr;
        }
        printf("\nInserted %d at Head",data);
    }
}
void insertPosition(int data,int position)
{
    struct DoublyLinkedList *temp;
    temp=head;
    int i=0;
    while(temp!=NULL)
    {
        if(i==position)
        {
            struct DoublyLinkedList *ptr;
            ptr = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
            ptr->key=data;
            ptr->next=temp;
            ptr->prev=temp->prev;
            temp->prev=ptr;
            if(ptr->prev!=NULL) ptr->prev->next = ptr;
            else head=ptr;
            break;
        }
        else
        {
            temp=temp->next;
            i++;
        }
    }
}
void insertAfter(int data,int data_after)
{
    struct DoublyLinkedList *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->key==data_after)
        {
            struct DoublyLinkedList *ptr;
            ptr = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
            ptr->key=data;
            ptr->next=temp->next;
            ptr->prev=temp;
            temp->next=ptr;
            if(ptr->next!=NULL)
            {
                ptr->next->prev=ptr;
            }
            break;
        }
        temp=temp->next;
    }
}
void insertBefore(int data,int data_before)
{
    struct DoublyLinkedList *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->key==data_before)
        {
            struct DoublyLinkedList *ptr;
            ptr = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
            ptr->key=data;
            ptr->next=temp;
            ptr->prev=temp->prev;
            temp->prev=ptr;
            if(ptr->prev!=NULL)
            {
                ptr->prev->next=ptr;
            }
            else head = ptr;
        }
        temp=temp->next;
    }
}
void searchList(int data)
{
    struct DoublyLinkedList *temp;
    int position = 0;
    if(isEmpty()) printf("Error : Empty List !");
    else
    {
        temp = head;
        while(temp!=NULL)
        {
            position++;
            if(temp->key==data)
            {
                printf("Found %d at %d",data,position-1);
                break;
            }
            temp = temp->next;
        }
    }
}
void displayList()
{
    struct DoublyLinkedList *temp;
    if(isEmpty()) printf("\nError : Empty List !");
    else
    {
        temp = head;
        printf("\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->key);
            temp = temp->next;
        }
    }
}
void deleteByValue(int data)
{
    struct DoublyLinkedList *temp;
    if(isEmpty()) printf("\nError : Empty List !");
    else
    {
        temp = head;
        while(temp!=NULL)
        {
            if(temp->key==data)
            {
                if(temp->prev!=NULL)
                {
                    temp->prev->next=temp->next;
                }
                if(temp->next!=NULL)
                {
                    temp->next->prev=temp->prev;
                }
                if(temp->prev==NULL && temp->next==NULL)
                {
                    head=NULL;
                }
                printf("\nDeleted : %d",data);
                break;
            }
            else temp=temp->next;
        }
    }
}
void deleteByPosition(int position)
{
    struct DoublyLinkedList *temp;
    if(isEmpty()) printf("\nError : Empty List !");
    else
    {
        temp = head;
        for(int i=0;i<position;i++)
        {
            temp = temp->next;
        }
        if(temp->prev!=NULL) temp->prev->next = temp->next;
        if(temp->next!=NULL) temp->next->prev = temp->prev;
        else head = temp->next;
        printf("\nDeleted : %d",temp->key);
    }
}
void main()
{
    int choice,data,data_after,data_before;
    do
    {
        printf("\nChoose an operation :");
        printf("\n1.Insert at Head");
        printf("\n2.Insert at Tail");
        printf("\n3.Insert before Node");
        printf("\n4.Insert after Node");
        printf("\n5.Search");
        printf("\n6.Display");
        printf("\n7.Delete by Value");
        printf("\n8.Delete by Position");
        printf("\n9.Exit");
        printf("\nEnter an option : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to insert :");
                scanf("%d",&data);
                insertionHead(data);
                break;
            case 2:
                printf("\nEnter the element to insert :");
                scanf("%d",&data);
                insertionTail(data);
                break;
            case 3:
                printf("\nEnter the element before which you want to insert :");
                scanf("%d",&data_before);
                printf("\nEnter the element to insert :");
                scanf("%d",&data);
                insertBefore(data,data_before);
                break;
            case 4:
                printf("\nEnter the element after which you want to insert :");
                scanf("%d",&data_after);
                printf("\nEnter the element to insert :");
                scanf("%d",&data);
                insertAfter(data,data_after);
                break;
            case 5:
                printf("\nEnter the element to search :");
                scanf("%d",&data);
                searchList(data);
                break;
            case 6:
                displayList();
                break;
            case 7:
                printf("\nEnter the element to delete :");
                scanf("%d",&data);
                deleteByValue(data);
                break;
            case 8:
                printf("\nEnter the position of element to delete :");
                scanf("%d",&data);
                deleteByPosition(data);
                break;
            case 9:
                break;
        }
    }
    while(choice<=8);
}