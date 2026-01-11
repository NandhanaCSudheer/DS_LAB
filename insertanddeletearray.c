#include <stdio.h>

int arr[10];     
int n = 0;      

void create(){
    printf("Enter the no. of elements in the array: \n");
    scanf("%d", &n);

    printf("Enter the elements: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
}

void insert(){
    int m, p;
    printf("Enter the element to be inserted: \n");
    scanf("%d", &m);

    printf("Enter the position where the element is to be inserted: \n");
    scanf("%d", &p);

    if (p < 0 || p > n) {
        printf("Invalid position\n");
        return;
    }

    for(int i = n; i > p; i--){
        arr[i] = arr[i - 1];
    }

    arr[p] = m;
    n++;
}

void delete(){
    int p;
    printf("Enter the position from where the element is to be deleted: \n");
    scanf("%d", &p);

    if (p < 0 || p >= n) {
        printf("Invalid position\n");
        return;
    }

    for(int i = p + 1; i < n; i++){
        arr[i - 1] = arr[i];
    }
    n--;
}

void display(){
    printf("The elements in the array are: \n");
    for(int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    int ch = 0;
    while (ch != 5){
        printf("\nMENU\n1.CREATE\n2.INSERT\n3.DELETE\n4.DISPLAY\n5.EXIT\nEnter your choice: \n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                delete();
                break;
            case 4:
                display();
                break;
            case 5:
                break;
        }
    }
    return 0;
}
