#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1;
int queue[50];   

void enqueue(int n){
    int val;

    if ((front == 0 && rear == n - 1) || (front == rear + 1)){
        printf("Queue is Full\n");
        return;
    }

    if (front == -1){
        front = rear = 0;
    }
    else if (rear == n - 1){
        rear = 0;
    }
    else{
        rear = rear + 1;
    }

    printf("Enter the value to be inserted: ");
    scanf("%d", &val);
    queue[rear] = val;
}

void dequeue(int n){
    if (front == -1){
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear){
        front = rear = -1;
    }
    else if (front == n - 1){
        front = 0;
    }
    else{
        front = front + 1;
    }
}

void display(int n){
    if (front == -1){
        printf("Queue is Empty\n");
        return;
    }

    if (front <= rear){
        for (int i = front; i <= rear; i++){
            printf("%d\n", queue[i]);
        }
    }
    else{
        for (int i = front; i < n; i++){
            printf("%d\n", queue[i]);
        }
        for (int i = 0; i <= rear; i++){
            printf("%d\n", queue[i]);
        }
    }
}

int main(){
    int n;
    int ch = 0;

    printf("Enter the no.of elements to be inserted: \n");
    scanf("%d", &n);

    while (ch != 4){
        printf("\nMENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\nEnter your choice: \n");
        scanf("%d", &ch);

        switch (ch){
            case 1:
                enqueue(n);
                break;
            case 2:
                dequeue(n);
                break;
            case 3:
                display(n);
                break;
            case 4:
                break;
        }
    }
    return 0;
}
