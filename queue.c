#include <stdio.h>
#define SIZE 5 
int queue[SIZE], front = -1, rear = -1;
int isFull() {
    return (rear == SIZE - 1);
}
int isEmpty() {
    return (front == -1 || front > rear);
}
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL! Cannot insert %d\n", value);
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("Inserted %d\n", value);
    }
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY! Cannot dequeue\n");
    } else {
        printf("Deleted %d\n", queue[front++]);
    }
}
void peek() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}
void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    peek();
    dequeue();
    display();
    return 0;
}
