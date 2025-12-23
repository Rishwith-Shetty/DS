#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *head=NULL;
void push(int value)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
}
void pop()
{
    if(head==NULL)
        printf("stack underflow\n");
    else if(head->next==NULL)
    {
        struct node *temp=head;
        head=NULL;
        printf("Deleted %d from stack...\n",temp->data);
        free(temp);

    }
    else{
        struct node *temp=head;
        head=head->next;
        printf("Deleted %d from stack\n",temp->data);
        free(temp);
    }
}
void enqueue(int value)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else{
        struct node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;

    }

}
void dequeue(){
    if(head==NULL)
        printf("queue underflow\n");
    else{
        struct node *temp=head;
        head=head->next;
        printf("Deleted %d from queue\n",temp->data);
        free(temp);
    }
}
void display()
{
    if(head==NULL)
        printf("no elements\n");
    else{
            struct node *temp=head;
            while(temp!=NULL){
                printf("%d->",temp->data);
                temp=temp->next;
            }
            printf("NULL\n");
    }


}
void main()
{
    int value,choice;
    printf("queue and stack implementation using linked list\n");
    printf("1.push  2.pop  3.enqueue  4.dequeue  5.display  6.exit\n");
    while(1)
    {
        printf("enter choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the element to push\n");
            scanf("%d",&value);
            push(value);
            break;
            case 2:pop();
            break;
            case 3:printf("Enter the element to insert into the queue\n");
            scanf("%d",&value);
            enqueue(value);
            break;
            case 4:dequeue();
            break;
            case 5:display();
            break;
            case 6:exit(0);

        }
    }
}
