#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};struct node *head=NULL;

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
    head=newnode;
    temp=head;
    
    for(int i=2;i<=n;i++){
        printf("Enter the %dth element: ",i);
        scanf("%d",&value);
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=head;
        temp->next=newnode;
        temp=temp->next;
    }
    return head;
}

struct node* insertatbeg(struct node *head){
    int value;
    struct node *newnode;
    struct node *temp;
    temp=head;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=temp;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
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
    temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
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
    newnode->next=ptr;
    return head;
}

struct node* deletefrombeg(struct node *head){
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct node *ptr;
     struct node *temp;
     temp=head;
     ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    head=head->next;
    ptr->next=head;
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
    struct node *ptr;
    while (temp->next->next!=head){
        temp = temp->next;
    }
    ptr=temp->next;
    temp->next=head;
    free(ptr);
    return head;
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
    for (int i = 0; i < pos-1 && temp->next!= head; i++){
        temp = temp->next;
    }
    ptr=temp->next;
    temp->next=ptr->next;
    free(ptr);
    return head;
}

void search(struct node *head){
    int key;
    int found=0;
     struct node *temp;
    temp=head;
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
     while(temp->next!=head){
        if(key==temp->data){
            found=1;
        }
        temp=temp->next;
     }
     if(key==temp->data){
        found=1;
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
     while(temp->next!=head){
        printf("%d\n",temp->data);
        temp=temp->next;
     }
     printf("%d\n",temp->data);
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