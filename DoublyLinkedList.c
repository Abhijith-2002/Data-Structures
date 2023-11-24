#include <stdio.h>
#include <stdlib.h>
struct DoublyLinkedList
{
    int key;
    struct DoublyLinkedList *next;
    struct DoublyLinkedList *prev;
};
struct DoublyLinkedList *head = NULL;
void insertionTail(int data)
{
    struct DoublyLinkedList *ptr,*temp;
    ptr = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
    if(ptr==NULL) printf("\nError : Memmory Allocation Failed !");
    else
    {
        ptr->key = data;
        if(head==NULL)
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
        printf("\nData Inserted");
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
        if(head==NULL)
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
    }
}
void searchList(int data)
{
    struct DoublyLinkedList *temp;
    temp = head;
    if(temp==NULL) printf("Error : Empty List !");
    else
    {
        while(temp->next!=NULL)
        {
            if(temp->key==data)
            {
                printf("Found");
                break;
            }
            temp = temp->next;
        }
    }
}
void displayList()
{
    struct DoublyLinkedList *temp;
    temp = head;
    if(temp==NULL) printf("Error : Empty List !");
    else
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->key);
            temp = temp->next;
        }
    }
}
void main()
{
    int choice,data;
    do
    {
        printf("\nChoose an operation :");
        printf("\n1.Insert at Head");
        printf("\n2.Insert at Tail");
        printf("\n3.Search");
        printf("\n4.Display");
        printf("\n5.Exit");
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
                printf("\nEnter the element to search :");
                scanf("%d",&data);
                searchList(data);
                break;
            case 4:
                displayList();
                break;
            case 5:
                break;
        }
    }
    while(choice<=4);
}