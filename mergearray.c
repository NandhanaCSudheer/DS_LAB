#include <stdio.h>

void mergearray() {
    int arr1[10], arr2[10], merged[20];
    int n1, n2;
    int i = 0, j = 0, k = 0;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);

    printf("Enter elements of first array in sorted order:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    int temp;
    for (int i = 0; i < n1 - 1; i++) {
        for (int j = 0; j < n1 - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);

    printf("Enter elements of second array in sorted order:\n");
    for (j = 0; j < n2; j++) {
        scanf("%d", &arr2[j]);
    }
    for (int i = 0; i < n2 - 1; i++) {
        for (int j = 0; j < n2 - i - 1; j++) {
            if (arr2[j] > arr2[j + 1]) {
                temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }

    i = j = 0;


    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    
    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    while (j < n2) {
        merged[k++] = arr2[j++];
    }

    printf("The merged array is:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", merged[i]);
    }
}

int main() {
    mergearray();
    return 0;
}
