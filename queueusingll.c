#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node* enqueue(struct node *rear){
    int value;
    struct node *new = (struct node *)malloc(sizeof(struct node));

    printf("Enter the value to be inserted: ");
    scanf("%d", &value);

    new->val = value;
    new->next = NULL;

    if (front == NULL) {    
        front = rear = new;
    } else {
        rear->next = new;
        rear = new;
    }

    printf("\nItem inserted\n");
    return rear;
}

struct node* dequeue(struct node *front){
    if (front == NULL) {
        printf("Queue is empty\n");
        return front;
    } else {
        struct node *ptr = front;
        front = front->next;
        free(ptr);

        if (front == NULL) {   
            rear = NULL;
        }

        printf("\nItem dequeued\n");
        return front;
    }
}

void display(struct node *front){
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("\nThe elements are:\n");
        while (front != NULL) {
            printf("%d\n", front->val);
            front = front->next;
        }
    }
}

int main(){
    int ch = 0;
    while (ch != 4){
        printf("\nMENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\nEnter your choice: \n");
        scanf("%d", &ch);
        switch (ch){
            case 1:
                rear = enqueue(rear);
                break;
            case 2:
                front = dequeue(front);
                break;
            case 3:
                display(front);
                break;
            case 4:
                break;
        }
    }
    return 0;
}
