#include<stdio.h>
#define Max 5
void commands() {
    printf("Operations : \n\t0 -> to print commands\n\t1 -> to push value in Queue\n\t2 - to pop value from Queue\n\t3 -> to display full Queue\n\t4 -> to exit from program\n");
}
void push(int *ptr, int *rear, int *front);
void pop(int *ptr, int *rear, int *front);
void display(int *ptr, int *rear, int *front);
void main() {
    commands();
    int front = -1, rear = -1, choice, val, arr[Max];
    while(1) {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if (choice == 4) {
            printf("exiting...\nexited successfully\n");
            break;
        }
        switch(choice) {
            case 0 :
                commands();
                break;
            case 1 :
                push(arr, &rear, &front);
                break;
            case 2 :
                pop(arr, &rear, &front);
                break;
            case 3 :
                display(arr, &rear, &front);
                break;
            default :
                printf("Error 0 : \n\tThere is not such choice available :<\n");
                break;
        }
    }
}
void push(int *ptr, int *rear, int *front) {
    if (*rear >= Max-1) {
        printf("Error -1 : \n\tQueue Overflow Exception\n\tQueue is already full!!\n");
        return;
    }
    if (*front == -1 && *rear == -1) {
        *front = 0;
        *rear = 0;
    } else {
        *rear = *rear + 1;
    }
    int val;
    printf("Enter the value to push into stack : ");
    scanf("%d", &val);
    *(ptr + *rear) = val;
}

void display(int *ptr, int *rear, int *front) {
    if (*rear == -1) {
        printf("Error 0 : \n\tQueue is empty!!\n\tPlease push some value to Queue\n");
        return;
    }
    if (*front > *rear) {
        printf("Error 0 : \n\tQueue is empty!!\n\tPlease push some value to Queue\n");
        return;
    }
    printf("Queue : \n");
    for(int i = *rear; i >= *front; i--) {
        printf("\t%d\n", *(ptr + i));
    }
}

void pop(int *ptr, int *rear, int *front) {
    if (*front <= -1) {
        printf("Error 1 : \n\tQueue Underflow Exception\n\nPlease push some value to pop from Queue\n");
        return;
    }
    int val = *(ptr + *front);
    printf("Value popped from Queue : %d\n", val);
    *front = *front +1;
    if (*front > *rear) {
        *front = -1;
        *rear = -1;
    }
    if (*front > Max-1) {
        *front = -1;
        *rear = -1;
    }

}