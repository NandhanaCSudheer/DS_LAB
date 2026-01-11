#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;


void createList() {
    int n, data;
    struct node *temp, *newnode;

    if (head != NULL) {
        printf("List already created\n");
        return;
    }

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &data);
    head = malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;

    temp = head;
    for (int i = 2; i <= n; i++) {
        newnode = malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }

    printf("List created successfully\n");
}


void traverse() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void insertAtBeg() {
    int data;
    struct node *newnode;

    printf("Enter data: ");
    scanf("%d", &data);

    newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}


void insertAtEnd() {
    int data;
    struct node *temp, *newnode;

    printf("Enter data: ");
    scanf("%d", &data);

    newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}


void insertAtPos() {
    int data, pos;
    struct node *temp, *newnode;

    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &data);

    if (pos == 1) {
        insertAtBeg();
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;
}


void deleteFromBeg() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}


void deleteFromEnd() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}


void deleteFromPos() {
    int pos;
    struct node *temp, *del;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        deleteFromBeg();
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;
    free(del);
}


void search() {
    int key, found = 0;
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (temp->data == key) {
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (found)
        printf("Element found\n");
    else
        printf("Element not found\n");
}


int main() {
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

        switch (choice) {
            case 1:
                 createList();
                 break;
            case 2:
                 insertAtBeg(); 
                 break;
            case 3: 
                 insertAtEnd(); 
                 break;
            case 4:
                 insertAtPos(); 
                 break;
            case 5:
                 deleteFromBeg();
                  break;
            case 6:
                 deleteFromEnd();
                 break;
            case 7:
                 deleteFromPos();
                 break;
            case 8:
                 search();
                 break;
            case 9:
                 traverse(); 
                 break;
            case 10:
                 exit(0);
            default:
                 printf("Invalid choice\n");
        }
    }
    return 0;
}
