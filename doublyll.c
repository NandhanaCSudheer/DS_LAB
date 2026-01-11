#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};struct node *head=NULL;
struct node *tail=NULL;

struct node* createnew(){
    int n,value;
    struct node *newnode;
    struct node *temp;
    printf("Enter the no. of elements to be entered: ");
    scanf("%d",&n);
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the first element to be inserted: ");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    head=newnode;
    temp=head;
    
    for(int i=2;i<=n;i++){
        printf("Enter the %dth element: ",i);
        scanf("%d",&value);
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=temp;
        temp->next=newnode;
        temp=temp->next;
    }
    return head;
}

struct node* insertatbeg(struct node *head){
    int value;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=head;
    newnode->prev=NULL;
    head=newnode;
    return head;
}

struct node *insertatend(struct node *head){
     int value;
    struct node *newnode;
    struct node *temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newnode->prev=temp;
    temp->next=newnode;
    return head;
}

struct node *insertatpos(struct node *head){
    int value,pos;
    struct node *newnode;
    struct node *temp;
    struct node *ptr;
    temp=head;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&value);
    printf("\nEnter the position where the element is to be inserted: ");
    scanf("%d",&pos);
    newnode->data=value;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    ptr=temp->next;
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=ptr;
    ptr->prev=newnode;
    return head;
}

struct node* deletefrombeg(struct node *head){
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

     struct node *temp;
     temp=head;
     head=head->next;
     if (head != NULL)
        head->prev = NULL;
     free(temp);
     return head;
}

struct node* deletefromend(struct node *head){
     if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
    return head;
     /*struct node *temp;
     struct node *ptr;
     temp=head;
     while(temp->next->next!=NULL){
        temp=temp->next;
    }
    ptr=temp->next;
    temp->next=NULL;
    free(ptr);
    return head;*/
}

struct node* deletefrompos(struct node *head){
     int pos;
     struct node *temp;
     struct node *ptr;
     temp=head;
       if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    printf("\nEnter the position from where the element is to be deleted: ");
    scanf("%d",&pos);
    if (pos == 1)
        return deletefrombeg(head);
    for (int i = 1; i < pos && temp != NULL; i++){
        temp = temp->next;
    }
     if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
    return head;
}

void search(struct node *head){
    int key;
    int found=0;
     struct node *temp;
    temp=head;
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
     while(temp!=NULL){
        if(key==temp->data){
            found=1;
        }
        temp=temp->next;
     }
     if(found==1){
        printf("The element found!!!");
     }
     else{
        printf("The element is not in the list!!!");
     }
}

void traverse(struct node *head){
     struct node *temp;
     temp=head;
     printf("The elements in the list are: \n");
     while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
     }
}

int main(){
    int choice;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Search\n");
        printf("9. Traverse\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                head=createnew();
                break;
            case 2:
                head=insertatbeg(head);
                break;
            case 3:
                head=insertatend(head);
                break;
            case 4:
                head=insertatpos(head);
                break;
            case 5:
                head=deletefrombeg(head);
                break;
            case 6:
                head=deletefromend(head);
                break;
            case 7:
                head=deletefrompos(head);
                break;
            case 8:
                search(head);
                break;
            case 9:
                traverse(head);
                break;
            case 10:
                exit(0);
                break;
        }
    }
}