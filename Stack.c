#include<stdio.h>
#define SIZE 100
int stack[SIZE],top=-1;
int stackEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else return 0;
}
void push(int data)
{
    if(top==(SIZE-1)) printf("Error : Stack Overflow\n");
    else
    {
        top++;
        stack[top]=data;
    }
}
void pop()
{
    if(stackEmpty()) printf("Error : Stack Underflow\n");
    else
    {
        top--;
        printf("Popped : %d\n",stack[top+1]);
    }
}
void peek()
{
    if(stackEmpty()) printf("Error : Stack is empty\n");
    else printf("Top : %d\n",stack[top]);
}
void display()
{
    if(stackEmpty()) printf("Error : Stack is empty\n");
    else
    {
        for(int i=0;i<=top;i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}
void main()
{
    int choice,data;
    do
    {
        printf("Choose an operation : \n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter an option : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to push :\n");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
    }
    while(choice<=4);
}
