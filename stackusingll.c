#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};struct node *head=NULL;

struct node* push(struct node *head){
    struct node *newnode;
    int value;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value to be inserted: ");
    scanf("%d",&value);
    newnode->val=value;
    newnode->next=head;
    head=newnode;
    printf("Item pushed ");
    return head;
}

struct node* pop(struct node *head){
    if (head==NULL){
        printf("Stack is Empty");
    }
    else{
        struct node *ptr=head;
        head = head->next;
        free(ptr);
        printf("Item popped");
    }
    return head;
}

void display(struct node *head){
    struct node *ptr;
    ptr=head;
    if(ptr==NULL){
        printf("Stack is Empty");
    }
    else{
        printf("The items in the stack are: \n");
        while(ptr!=NULL){
            printf("%d\n",ptr->val);
            ptr=ptr->next;
        }
    }
}

int main(){
    int ch=0;
    while (ch!=4){
        printf("\nMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nEnter your choice: \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                head=push(head);
                break;
            case 2:
                head=pop(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                break;
        }
    }
    return 0;
}